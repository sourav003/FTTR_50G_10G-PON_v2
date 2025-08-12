/*
 * source.cc
 *
 *  Created on: 30 July 2025
 *      Author: mondals
 */

#include <string.h>
#include <math.h>
#include <omnetpp.h>
#include <numeric>   // Required for std::iota
#include <algorithm> // Required for std::sort

#include "sim_params.h"
#include "ethPacket_m.h"
#include "ping_m.h"
#include "gtc_header_m.h"

using namespace std;
using namespace omnetpp;

/*
 * Each source generates packets following some probability distribution.
 * The average inter-arrival time is derived using the maximum datarate of the
 * SourceApp and average packet size.
 * The generateEvent is a self-message which is scheduled back-to-back to create
 * a new packet. Immediately the packet is transmitted to the corresponding ONU.
 */

class Background_Device : public cSimpleModule
{
    private:
        cQueue source_queue;                        // Queue for holding packets to be sent to ONUs/SFUs
        double src_queue_size;
        double Load;
        double ArrivalRate;
        double pkt_interval;                        // inter-packet generation interval
        double wireless_datarate;
        cMessage *generateEvent = nullptr;          // holds pointer to the self-timeout message

        //simsignal_t arrivalSignal;               // to send signals for statistics collection

    public:
        virtual ~Background_Device();

    protected:
        // The following redefined virtual function holds the algorithm.
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual ethPacket *generateNewPacket();
};

// The module class needs to be registered with OMNeT++
Define_Module(Background_Device);

Background_Device::~Background_Device()
{
    cancelAndDelete(generateEvent);
    // Clean up queues
    while (!source_queue.isEmpty()) {
        delete source_queue.pop();
    }
}

void Background_Device::initialize()
{
    //arrivalSignal = registerSignal("generation");              // registering the signal

    cGate *src_gate = gate("out");
    cChannel *src_ch = src_gate->getChannel();
    wireless_datarate = src_ch->par("datarate").doubleValue();

    source_queue.setName("source_queue");
    src_queue_size = 0;

    Load = par("load");                                         // get the load factor from NED file
    double R_o = par("dataRate");                                 // get the max ONU datarate from NED file
    ArrivalRate = Load*R_o/(8*pkt_sz_avg);                             // average packet arrival rate with datarate in bytes
    //EV << "[srcBkg] data rate = " << R_o << endl;

    // Initialize variables
    pkt_interval = exponential(1/ArrivalRate);                  // packet inter-arrival times are generated following exponential distribution
    generateEvent = new cMessage("generateEvent");              // self-message is generated for next packet generation
    //emit(arrivalSignal,pkt_interval);

    ethPacket *pkt = generateNewPacket();                       // generating the first packet at T = 0
    send(pkt,"out");
    //EV << "[srcBkg] pkt_interval = " << pkt_interval << " and current time = " << simTime() << endl;

    scheduleAt(simTime()+pkt_interval, generateEvent);          // scheduling the next packet generation
}

void Background_Device::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(),"generateEvent") == 0) {
        pkt_interval = exponential(1/ArrivalRate);              // packet inter-arrival time generation
        scheduleAt(simTime()+pkt_interval, generateEvent);      // scheduling the next packet generation
        //emit(arrivalSignal,pkt_interval);
        //EV << "[srcBkg] pkt_interval = " << pkt_interval << " and current time = " << simTime() << endl;

        cPacket *pkt = generateNewPacket();                     // generating a new packet at current time
        cGate *src_gate = gate("out");
        cChannel *src_ch = src_gate->getChannel();
        if(src_ch->isBusy() == false) {
            send(pkt,"out");
        }
        else {
            source_queue.insert(pkt);
            cMessage *src_tx = new cMessage("Source_Tx_Delay");
            scheduleAt(src_ch->getTransmissionFinishTime()+(simtime_t)(src_queue_size*8/wireless_datarate),src_tx);
            src_queue_size += pkt->getByteLength();
        }
    }
    else if(strcmp(msg->getName(),"Source_Tx_Delay") == 0) {
        delete msg;

        ethPacket *pkt = (ethPacket *)source_queue.pop();
        src_queue_size -= pkt->getByteLength();

        cGate *src_gate = gate("out");
        cChannel *src_ch = src_gate->getChannel();
        if(src_ch->isBusy() == false) {             // just to be sure that the channel is free now
            send(pkt,"out");
        }
        else {
            if(source_queue.isEmpty()) {
                source_queue.insert(pkt);
            }
            else {
                source_queue.insertBefore(source_queue.front(), pkt);
            }
            src_queue_size += pkt->getByteLength();
            cMessage *src_tx = new cMessage("Source_Tx_Delay");
            scheduleAt(src_ch->getTransmissionFinishTime(),src_tx);
        }
    }
}

ethPacket *Background_Device::generateNewPacket()
{
    int pkt_size = intuniform(64,1542);
    //int pkt_size = intuniform(64,1000);             // for testing 1:16 1-GPON without fragmentation
    ethPacket *pkt = new ethPacket("bkg_data");
    pkt->setByteLength(pkt_size);                     // adding a random size payload to the packet
    pkt->setGenerationTime(simTime());
    //EV << "[srcBkg] New packet generated with size (bytes): " << pkt_size << endl;
    return pkt;
}


