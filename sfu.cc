/*
 * sfu.cc
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

class SFU : public cSimpleModule
{
    private:
        cQueue queue_TC1;                       // queue for T-CONT 1 traffic: fixed bandwidth with guarantee
        cQueue queue_TC2;                       // queue for T-CONT 2 traffic: assured bandwidth with bound
        cQueue queue_TC3;                       // queue for T-CONT 3 traffic: assured bandwidth without guarantee
        cQueue gtc_dl_queue;                    // queue to store gtc_dl_headers
        double capacity;                        // buffer size = 100 MB
        double pending_buffer_TC1 = 0;          // pending data size in buffer
        double pending_buffer_TC2 = 0;
        double pending_buffer_TC3 = 0;
        double packet_drop_count = 0;
        double mfu_sfu_rtt = 0;
        double start_time_TC1 = 0;
        double sfu_grant_TC1 = 0;
        double start_time_TC2 = 0;
        double sfu_grant_TC2 = 0;
        double start_time_TC3 = 0;
        double sfu_grant_TC3 = 0;
        double gtc_hdr_sz = 0;
        long seqID;

        //simsignal_t latencySignalXr;
        //simsignal_t latencySignalBkg;

    public:
        virtual ~SFU();

    protected:
        // The following redefined virtual function holds the algorithm.
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
};

Define_Module(SFU);

void SFU::initialize()
{
    //latencySignalXr = registerSignal("xr_latency");                     // registering the signal
    //latencySignalBkg = registerSignal("bkg_latency");

    queue_TC1.setName("queue_TC1");
    queue_TC2.setName("queue_TC2");
    queue_TC3.setName("queue_TC3");
    gtc_dl_queue.setName("gtc_dl_queue");
    capacity = sfu_buffer_capacity;

    gate("inWap")->setDeliverImmediately(true);
    gate("SpltGate_in")->setDeliverImmediately(true);
}

SFU::~SFU()
{
    // Clean up queues
    while (!queue_TC1.isEmpty()) {
        delete queue_TC1.pop();
    }
    while (!queue_TC2.isEmpty()) {
        delete queue_TC2.pop();
    }
    while (!queue_TC3.isEmpty()) {
        delete queue_TC3.pop();
    }
    while (!gtc_dl_queue.isEmpty()) {
        delete gtc_dl_queue.pop();
    }
}

void SFU::handleMessage(cMessage *msg)
{
    if(msg->isPacket() == true) {
        if(strcmp(msg->getName(),"bkg_data") == 0) {                    // background traffic is considered for T-CONT 3
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);
            double buffer = pending_buffer_TC1 + pending_buffer_TC2 + pending_buffer_TC3 + pkt->getByteLength();      // future buffer size if current packet is queued
            if(buffer <= sfu_buffer_capacity) {                         // queue the current packet if there is buffer capacity
                pkt->setSfuArrivalTime(pkt->getArrivalTime());
                pkt->setSfuId(getIndex());
                pkt->setTContId(3);                                     // for TC-3
                //EV << "[sfu" << getIndex() << "] Packet arrived from source and being queued at SFU" << endl;
                queue_TC3.insert(pkt);
                pending_buffer_TC3 += pkt->getByteLength();

                //EV << "[sfu" << getIndex() << "] Current TC3 queue length = " << queue_TC3.getLength() << " at SFU = " << getIndex() <<endl;
                //EV << "[sfu" << getIndex() << "] Current buffer length = " << pending_buffer_TC3 << " at SFU = " << getIndex() <<endl;
            }
            //delete pkt;
        }
        else if(strcmp(msg->getName(),"xr_data") == 0) {                    // background traffic is considered for T-CONT 3
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);
            double buffer = pending_buffer_TC1 + pending_buffer_TC2 + pending_buffer_TC3 + pkt->getByteLength();      // future buffer size if current packet is queued
            if(buffer <= sfu_buffer_capacity) {                             // queue the current packet if there is buffer capacity
                pkt->setSfuArrivalTime(pkt->getArrivalTime());
                pkt->setSfuId(getIndex());
                pkt->setTContId(2);                 // for TC-2
                //pkt->setTContId(3);               // for TC-3
                //EV << "[sfu" << getIndex() << "] Packet arrived from source and being queued at SFU" << endl;
                queue_TC2.insert(pkt);
                //queue_TC3.insert(pkt);
                pending_buffer_TC2 += pkt->getByteLength();
                //pending_buffer_TC3 += pkt->getByteLength();

                //EV << "[sfu" << getIndex() << "] Current TC2 queue length = " << queue_TC2.getLength() << " at SFU = " << getIndex() <<endl;
                //EV << "[sfu" << getIndex() << "] Current buffer length = " << pending_buffer_TC2 << " at SFU = " << getIndex() <<endl;
            }
            //delete pkt;
        }
        else if(strcmp(msg->getName(),"hmd_data") == 0) {                    // background traffic is considered for T-CONT 3
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);
            double buffer = pending_buffer_TC1 + pending_buffer_TC2 + pending_buffer_TC3 + pkt->getByteLength();      // future buffer size if current packet is queued
            if(buffer <= sfu_buffer_capacity) {                             // queue the current packet if there is buffer capacity
                pkt->setSfuArrivalTime(pkt->getArrivalTime());
                pkt->setSfuId(getIndex());
                pkt->setTContId(2);                 // for TC-2
                //pkt->setTContId(3);               // for TC-3
                //EV << "[sfu" << getIndex() << "] Packet arrived from source and being queued at SFU" << endl;
                queue_TC2.insert(pkt);
                //queue_TC3.insert(pkt);
                pending_buffer_TC2 += pkt->getByteLength();
                //pending_buffer_TC3 += pkt->getByteLength();

                //EV << "[sfu" << getIndex() << "] Current TC2 queue length = " << queue_TC2.getLength() << " at SFU = " << getIndex() <<endl;
                //EV << "[sfu" << getIndex() << "] Current buffer length = " << pending_buffer_TC2 << " at SFU = " << getIndex() <<endl;
            }
            //delete pkt;
        }
        else if(strcmp(msg->getName(),"control_data") == 0) {                    // background traffic is considered for T-CONT 3
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);
            double buffer = pending_buffer_TC1 + pending_buffer_TC2 + pending_buffer_TC3 + pkt->getByteLength();      // future buffer size if current packet is queued
            if(buffer <= sfu_buffer_capacity) {                             // queue the current packet if there is buffer capacity
                pkt->setSfuArrivalTime(pkt->getArrivalTime());
                pkt->setSfuId(getIndex());
                pkt->setTContId(2);                 // for TC-2
                //pkt->setTContId(3);               // for TC-3
                //EV << "[sfu" << getIndex() << "] Packet arrived from source and being queued at SFU" << endl;
                queue_TC2.insert(pkt);
                //queue_TC3.insert(pkt);
                pending_buffer_TC2 += pkt->getByteLength();
                //pending_buffer_TC3 += pkt->getByteLength();

                //EV << "[sfu" << getIndex() << "] Current TC2 queue length = " << queue_TC2.getLength() << " at SFU = " << getIndex() <<endl;
                //EV << "[sfu" << getIndex() << "] Current buffer length = " << pending_buffer_TC2 << " at SFU = " << getIndex() <<endl;
            }
            //delete pkt;
        }
        else if(strcmp(msg->getName(),"haptic_data") == 0) {                    // background traffic is considered for T-CONT 3
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);
            double buffer = pending_buffer_TC1 + pending_buffer_TC2 + pending_buffer_TC3 + pkt->getByteLength();      // future buffer size if current packet is queued
            if(buffer <= sfu_buffer_capacity) {                             // queue the current packet if there is buffer capacity
                pkt->setSfuArrivalTime(pkt->getArrivalTime());
                pkt->setSfuId(getIndex());
                pkt->setTContId(2);                 // for TC-2
                //pkt->setTContId(3);               // for TC-3
                //EV << "[sfu" << getIndex() << "] Packet arrived from source and being queued at SFU" << endl;
                queue_TC2.insert(pkt);
                //queue_TC3.insert(pkt);
                pending_buffer_TC2 += pkt->getByteLength();
                //pending_buffer_TC3 += pkt->getByteLength();

                //EV << "[sfu" << getIndex() << "] Current TC2 queue length = " << queue_TC2.getLength() << " at SFU = " << getIndex() <<endl;
                //EV << "[sfu" << getIndex() << "] Current buffer length = " << pending_buffer_TC2 << " at SFU = " << getIndex() <<endl;
            }
            //delete pkt;
        }
        else if(strcmp(msg->getName(),"gtc_hdr_dl") == 0) {
            gtc_header *pkt = check_and_cast<gtc_header *>(msg);
            simtime_t arr_time = pkt->getArrivalTime();
            EV << "[sfu" << getIndex() << "] gtc_hdr_dl arrival time: " << arr_time << endl;

            //int totalNodes = getParentModule()->getSubmodule("sfus", 0)->getVectorSize();
            int totalNodes = getParentModule()->par("NumberOfSFUs");
            int index =  getIndex() % totalNodes;
            EV << "[sfu" << getIndex() << "] totalNodes = "<< totalNodes << ", actual id: "<< index << endl;
            mfu_sfu_rtt = pkt->getMfu_sfu_rtt(index);
            start_time_TC2 = pkt->getSfu_start_time_TC2(index);

            EV << "[sfu" << getIndex() << "] mfu_sfu_rtt: " << mfu_sfu_rtt << ", start_time_TC2: " << start_time_TC2 << endl;

            simtime_t ul_tx_time = arr_time + (simtime_t)(2*max_polling_cycle + start_time_TC2 - mfu_sfu_rtt);      // if RTT > 125/2 usec, then multiply by 2, else 1
            // - (pkt->getBitLength()/pon_link_datarate)
            cMessage *send_ul_header = new cMessage("send_ul_header");    // send uplink data
            scheduleAt(ul_tx_time, send_ul_header);
            //EV << "[sfu" << getIndex() << "] send_ul_header is scheduled at: " << ul_tx_time << endl;

            //delete pkt;
            gtc_dl_queue.insert(pkt);
        }
    }
    else {      // if not packet but a message
        if(strcmp(msg->getName(),"ping") == 0) {
            ping *png = check_and_cast<ping *>(msg);
            png->setSFU_id(getIndex());                 // the index will be re-adjusted at MFU
            send(png,"SpltGate_out");                                  // immediately send the ping message back
            EV << "[sfu" << getIndex() << "] Sending ping response from SFU-" << getIndex() << " at " << simTime() << endl;
        }
        else if(strcmp(msg->getName(),"send_ul_header") == 0) {
            cancelAndDelete(msg);         // delete the current instance of self-message

            gtc_hdr_sz = 3 + 1 + 1 + 5 + 8;                   // total size of GTC UL header: Preamble+Delim+BIP+PLOu_Header
            if(!gtc_dl_queue.isEmpty()) {
                gtc_header *dl_hdr = (gtc_header *)gtc_dl_queue.pop();
                int totalNodes = getParentModule()->par("NumberOfSFUs");
                int index =  getIndex() % totalNodes;
                sfu_grant_TC2 = std::max(0.0,dl_hdr->getSfu_grant_TC2(index));
                sfu_grant_TC3 = std::max(0.0,dl_hdr->getSfu_grant_TC3(index) - gtc_hdr_sz);
                seqID = dl_hdr->getSeqID();
                delete dl_hdr;          // deleting the used gtc_dl_header
            }
            else {
                sfu_grant_TC2 = 0;
                sfu_grant_TC3 = 0;
            }

            gtc_header *gtc_hdr_ul = new gtc_header("gtc_hdr_ul");
            gtc_hdr_ul->setByteLength(gtc_hdr_sz);
            gtc_hdr_ul->setUplink(true);
            gtc_hdr_ul->setSfuID(getIndex());
            gtc_hdr_ul->setBufferOccupancyTC2(pending_buffer_TC2);
            gtc_hdr_ul->setBufferOccupancyTC3(pending_buffer_TC3);

            EV << "[sfu" << getIndex() << "] Sending gtc_hdr_ul from SFU-" << getIndex() << " at = " << simTime() << " for seqID = " << seqID << endl;
            send(gtc_hdr_ul,"SpltGate_out");

            simtime_t Txtime = (simtime_t)(gtc_hdr_ul->getBitLength()/int_pon_link_datarate);

            cMessage *send_ul_payload = new cMessage("send_ul_payload_TC2");            // send uplink data
            scheduleAt(gtc_hdr_ul->getSendingTime()+Txtime, send_ul_payload);
            //EV << "[sfu" << getIndex() << "] send_ul_payload first time created and scheduled!" << endl;

            //EV << "[sfu" << getIndex() << "] latest pending_buffer_TC3: " << pending_buffer_TC3 << endl;
        }
        else if(strcmp(msg->getName(),"send_ul_payload_TC2") == 0) {
            // for T-CONT 2
            if((sfu_grant_TC2 > 0)&&(pending_buffer_TC2 > 0)) {
                if(!queue_TC2.isEmpty()) {
                    ethPacket *front = (ethPacket *)queue_TC2.front();
                    if(front->getByteLength() <= sfu_grant_TC2) {                // check if the first packet can be sent now
                        ethPacket *data = (ethPacket *)queue_TC2.pop();          // pop and send the packet
                        sfu_grant_TC2 = std::max(0.0,sfu_grant_TC2-data->getByteLength());
                        pending_buffer_TC2 = std::max(0.0,pending_buffer_TC2-data->getByteLength());

                        EV << "[sfu" << getIndex() << "] at " << simTime() << " Sending ul payload: " << data->getByteLength() << ", pending_buffer_TC2 = " << pending_buffer_TC2 << ", sfu_grant_TC2 = " << sfu_grant_TC2 << endl;
                        send(data,"SpltGate_out");
                        data->setSfuDepartureTime(data->getSendingTime());

                        //double xr_packet_latency = data->getSfuDepartureTime().dbl() - data->getSfuArrivalTime().dbl();
                        //EV << "[onu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                        //emit(latencySignalXr, xr_packet_latency);

                        // rescheduling send_ul_payload to send the consecutive queued packets
                        simtime_t Txtime = (simtime_t)(data->getBitLength()/int_pon_link_datarate);
                        scheduleAt(data->getSendingTime()+Txtime,msg);
                        //EV << "[sfu" << getIndex() << "] send_ul_payload re-scheduled!" << endl;
                    }
                    else {      // if the remaining grant is insufficient to send the next packet
                        //EV << "[sfu" << getIndex() << "] sfu_grant_TC2: " << sfu_grant_TC2 << " is insufficient to send a complete packet!" << endl;
                        if (!queue_TC2.isEmpty()) {
                            ethPacket *data = (ethPacket *)queue_TC2.pop();          // pop and send the packet
                            double pkt_size = data->getByteLength();
                            ethPacket *copy = data->dup();                            // creating a copy for all and sending immediately
                            copy->setByteLength(sfu_grant_TC2);
                            int fragment_count = data->getFragmentCount()+1;
                            copy->setFragmentCount(fragment_count);
                            data->setFragmentCount(fragment_count);

                            send(copy,"SpltGate_out");
                            copy->setSfuDepartureTime(copy->getSendingTime());

                            data->setByteLength(pkt_size - sfu_grant_TC2);
                            if(!queue_TC2.isEmpty()) {
                                queue_TC2.insertBefore(queue_TC2.front(), data);
                            }
                            else {
                                queue_TC2.insert(data);
                            }
                            //EV << "[sfu" << getIndex() << "] at " << simTime() << " sent fragmented packet of size: " << onu_grant_TC2 << " and en-queued packet of size = " << data->getByteLength() << endl;

                            pending_buffer_TC2 = std::max(0.0,pending_buffer_TC2 - sfu_grant_TC2);
                            sfu_grant_TC2 = 0;          // grant exhausted!

                            //double xr_packet_latency = copy->getSfuDepartureTime().dbl() - copy->getSfuArrivalTime().dbl();
                            //EV << "[sfu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                            //emit(latencySignalXr, xr_packet_latency);

                            //delete msg;   // cleaning up packetSend msg
                            simtime_t Txtime = (simtime_t)(copy->getBitLength()/int_pon_link_datarate);
                            scheduleAt(copy->getSendingTime()+Txtime,msg);
                            EV << "[sfu" << getIndex() << "] 246 ul TC2 transmission finished at: " << simTime() << " for seqID = " << seqID << endl;
                        }
                    }
                }
                else {
                    delete msg;
                    EV << "[sfu" << getIndex() << "] queue_TC2 is empty at: " << simTime() << endl;
                }
            }
            else {  // either grant <= 0 or pending_buffer = 0
                EV << "[sfu" << getIndex() << "] 254 ul TC2 transmission finished at: " << simTime() << " for seqID = " << seqID << endl;
                delete msg;   // cleaning up packetSend msg

                cMessage *send_ul_payload = new cMessage("send_ul_payload_TC3");            // send uplink data
                scheduleAt(simTime(), send_ul_payload);
            }
        }
        else if(strcmp(msg->getName(),"send_ul_payload_TC3") == 0) {
            // for T-CONT 3
            EV << "[sfu" << getIndex() << "] sfu_grant_TC3: " << sfu_grant_TC3 << ", pending_buffer_TC3 = " << pending_buffer_TC3 << ", msg->isScheduled(): " << msg->isScheduled() << endl;
            if((sfu_grant_TC3 > 0)&&(pending_buffer_TC3 > 0)&&(!msg->isScheduled())) {
                //EV << "[onu" << getIndex() << "] queue_TC3.isEmpty(): " << queue_TC3.isEmpty() << endl;
                if(!queue_TC3.isEmpty()) {
                    ethPacket *front = (ethPacket *)queue_TC3.front();
                    if(front->getByteLength() <= sfu_grant_TC3) {                // check if the first packet can be sent now
                        ethPacket *data = (ethPacket *)queue_TC3.pop();          // pop and send the packet
                        sfu_grant_TC3 = std::max(0.0,sfu_grant_TC3-data->getByteLength());
                        pending_buffer_TC3 = std::max(0.0,pending_buffer_TC3-data->getByteLength());

                        EV << "[sfu" << getIndex() << "] at " << simTime() << " Sending ul payload: " << data->getByteLength() << ", pending_buffer_TC3 = " << pending_buffer_TC3 << ", sfu_grant_TC3 = " << sfu_grant_TC3 << endl;
                        send(data,"SpltGate_out");
                        data->setSfuDepartureTime(data->getSendingTime());

                        if(strcmp(data->getName(),"bkg_data") == 0) {
                            //double bkg_packet_latency = data->getSfuDepartureTime().dbl() - data->getSfuArrivalTime().dbl();
                            //EV << "[sfu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                            //emit(latencySignalBkg, bkg_packet_latency);
                        }
                        /*if(strcmp(data->getName(),"xr_data") == 0) {
                            double xr_packet_latency = data->getSfuDepartureTime().dbl() - data->getSfuArrivalTime().dbl();
                            //EV << "[sfu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                            emit(latencySignalXr, xr_packet_latency);
                        }*/

                        // rescheduling send_ul_payload to send the consecutive queued packets
                        if(pending_buffer_TC3 > 0) {
                            simtime_t Txtime = (simtime_t)(data->getBitLength()/int_pon_link_datarate);
                            scheduleAt(data->getSendingTime()+Txtime,msg);
                            //EV << "[sfu" << getIndex() << "] send_ul_payload re-scheduled!" << endl;
                        }
                        else {
                            EV << "[sfu" << getIndex() << "] deleting msg @ 282" << endl;
                            delete msg;
                        }
                    }
                    else {      // if the remaining grant is insufficient to send the next packet
                        //EV << "[sfu" << getIndex() << "] sfu_grant_TC3: " << sfu_grant_TC3 << " is insufficient to send a complete packet!" << endl;
                        if (!queue_TC3.isEmpty()) {
                            ethPacket *data = (ethPacket *)queue_TC3.pop();          // pop and send the packet
                            double pkt_size = data->getByteLength();
                            ethPacket *copy = data->dup();                            // creating a copy for all and sending immediately
                            copy->setByteLength(sfu_grant_TC3);
                            int fragment_count = data->getFragmentCount()+1;
                            copy->setFragmentCount(fragment_count);
                            data->setFragmentCount(fragment_count);

                            send(copy,"SpltGate_out");
                            copy->setSfuDepartureTime(copy->getSendingTime());

                            data->setByteLength(pkt_size - sfu_grant_TC3);
                            if(!queue_TC3.isEmpty()) {
                                queue_TC3.insertBefore(queue_TC3.front(), data);
                            }
                            else {
                                queue_TC3.insert(data);
                            }
                            //EV << "[sfu" << getIndex() << "] at " << simTime() << " sent fragmented packet of size: " << sfu_grant_TC3 << " and en-queued packet of size = " << data->getByteLength() << endl;

                            pending_buffer_TC3 = std::max(0.0,pending_buffer_TC3 - sfu_grant_TC3);
                            sfu_grant_TC3 = 0;          // grant exhausted!

                            /*if(strcmp(data->getName(),"bkg_data") == 0) {
                                double bkg_packet_latency = data->getSfuDepartureTime().dbl() - data->getSfuArrivalTime().dbl();
                                //EV << "[sfu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                                emit(latencySignalBkg, bkg_packet_latency);
                            }
                            if(strcmp(data->getName(),"xr_data") == 0) {
                                double xr_packet_latency = data->getSfuDepartureTime().dbl() - data->getSfuArrivalTime().dbl();
                                //EV << "[sfu" << getIndex() << "] packet_latency: " << packet_latency << endl;
                                emit(latencySignalXr, xr_packet_latency);
                            }*/

                            delete msg;   // cleaning up packetSend msg
                            EV << "[sfu" << getIndex() << "] deleting msg @ 320" << endl;
                            /*simtime_t Txtime = (simtime_t)(copy->getBitLength()/int_pon_link_datarate);
                            scheduleAt(copy->getSendingTime()+Txtime,msg);*/
                            EV << "[sfu" << getIndex() << "] 322 ul TC3 transmission finished at: " << simTime() << " for seqID = " << seqID << endl;
                        }
                    }
                }
                else {
                    delete msg;
                    EV << "[sfu" << getIndex() << "] queue_TC3 is empty at: " << simTime() << " deleting msg @ 329" << endl;
                }
            }
            else {
                    EV << "[sfu" << getIndex() << "] 332 ul TC3 transmission finished at: " << simTime() << " for seqID = " << seqID << endl;
                    delete msg;   // cleaning up packetSend msg
                    EV << "[sfu" << getIndex() << "] deleting msg @ 335" << endl;
            }
        }
    }
}





