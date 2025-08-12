/*
 * source_hmd.cc
 *
 *  Created on: 8 Aug 2025
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

class HMD_Device : public cSimpleModule
{
    private:
        cQueue source_queue;                        // Queue for holding packets to be sent to ONUs/SFUs
        double src_queue_size;
        double avgPacketSize;
        double ArrivalRate;
        double pkt_interval;                     // inter-packet generation interval
        double wireless_datarate;
        cMessage *generateEvent = nullptr;       // holds pointer to the self-timeout message

    //simsignal_t arrivalSignal;               // to send signals for statistics collection

    public:
        virtual ~HMD_Device();

    protected:
        // The following redefined virtual function holds the algorithm.
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        virtual ethPacket *generateNewPacket();
};

// The module class needs to be registered with OMNeT++
Define_Module(HMD_Device);

HMD_Device::~HMD_Device()
{
    cancelAndDelete(generateEvent);
    // Clean up queues
    while (!source_queue.isEmpty()) {
        delete source_queue.pop();
    }
}

void HMD_Device::initialize()
{
    //arrivalSignal = registerSignal("generation");              // registering the signal

    cGate *src_gate = gate("out");
    cChannel *src_ch = src_gate->getChannel();
    wireless_datarate = src_ch->par("datarate").doubleValue();

    source_queue.setName("source_queue");
    src_queue_size = 0;

    avgPacketSize = par("meanPacketSize");                      // get the avg packet size from NED file
    ArrivalRate   = par("sampleRate");                          // get the HMD location sample rate from NED file (1/15e-3 per sec)

    // Initialize variables
    double sd = 0.5;
    double scale_b = sd*sqrt(ArrivalRate);                      // beta = sd^2/mean, assuming sd = 1 ms
    double shape_a = (1/ArrivalRate)/scale_b;                   // alpha = mean/beta
    pkt_interval = 1e-3*gamma_d(shape_a,scale_b);               // packet inter-arrival times are generated following gamma distribution

    generateEvent = new cMessage("generateEvent");              // self-message is generated for next packet generation
    //emit(arrivalSignal,pkt_interval);

    ethPacket *pkt = generateNewPacket();                       // generating the first packet at T = 0
    send(pkt,"out");
    //EV << "[srcHMD] pkt_interval = " << pkt_interval << " and current time = " << simTime() << endl;

    scheduleAt(simTime()+pkt_interval, generateEvent);          // scheduling the next packet generation
}

void HMD_Device::handleMessage(cMessage *msg)
{
    if(strcmp(msg->getName(),"generateEvent") == 0) {
        double sd = 0.5;
        double scale_b = sd*sqrt(ArrivalRate);                      // beta = sd^2/mean, assuming sd = 1 ms
        double shape_a = (1/ArrivalRate)/scale_b;                   // alpha = mean/beta
        pkt_interval = 1e-3*gamma_d(shape_a,scale_b);               // packet inter-arrival times are generated following gamma distribution

        scheduleAt(simTime()+pkt_interval, generateEvent);      // scheduling the next packet generation
        //emit(arrivalSignal,pkt_interval);
        //EV << "[srcHpt] pkt_interval = " << pkt_interval << " and current time = " << simTime() << endl;

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

ethPacket *HMD_Device::generateNewPacket()
{
    ethPacket *pkt = new ethPacket("hmd_data");
    pkt->setByteLength(avgPacketSize);                              // generating packets of same size
    pkt->setGenerationTime(simTime());
    //EV << "[srcHMD] New packet generated with size (bytes): " << avgPacketSize << endl;
    return pkt;
}






