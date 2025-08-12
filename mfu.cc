/*
 * mfu.cc
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

class MFU : public cSimpleModule
{
    private:
        vector<double> sfu_rtt;
        vector<double> sfu_buffer_TC1;
        vector<double> sfu_buffer_TC2;
        vector<double> sfu_buffer_TC3;
        vector<double> sfu_grant_TC1;
        vector<double> sfu_grant_TC2;
        vector<double> sfu_grant_TC3;
        vector<double> sfu_start_time_TC1;
        vector<double> sfu_start_time_TC2;
        vector<double> sfu_start_time_TC3;
        vector<int> sfu_index;
        vector<double> sfu_tx_start_TC1;
        vector<double> sfu_tx_start_TC2;
        vector<double> sfu_tx_start_TC3;
        long seqID = 0;

        int sfus;
        int ping_count = 0;
        double sfu_max_grant;

        //simsignal_t errorSignal;

    public:
        //virtual ~MFU();

    protected:
        double ber;
        long totalBitsReceived = 0;
        long totalPacketsReceived = 0;
        long corruptedPackets = 0;

        // The following redefined virtual function holds the algorithm.
        virtual void initialize() override;
        virtual void handleMessage(cMessage *msg) override;
        //virtual ponPacket *generateGrantPacket();
};

Define_Module(MFU);

void MFU::initialize()
{
    //errorSignal = registerSignal("pkt_error");  // registering the signal

    gate("SpltGate_i")->setDeliverImmediately(true);

    sfus = par("NumberOfSFUs");
    EV << "[mfu" << getIndex() << "] No. of sfus detected = " << sfus << endl;

    sfu_rtt.resize(sfus,0.0);
    sfu_buffer_TC1.resize(sfus,0.0);
    sfu_buffer_TC2.resize(sfus,0.0);
    sfu_buffer_TC3.resize(sfus,0.0);
    sfu_grant_TC1.resize(sfus,0.0);
    sfu_grant_TC2.resize(sfus,0.0);
    sfu_grant_TC3.resize(sfus,0.0);
    sfu_start_time_TC1.resize(sfus,0.0);
    sfu_start_time_TC2.resize(sfus,0.0);
    sfu_start_time_TC3.resize(sfus,0.0);

    for(int j = 0; j<sfus; j++) {
        sfu_index.push_back(j);
    }

    //EV << "[mfu" << getIndex() << "] onu_rtt[0] = " << onu_rtt[0] << ", onu_rtt[1] = " << onu_rtt[1] << endl;
    // bw_map = [onu_id, tc_type, start_time, grant_size]

    ping *png = new ping("ping");      // sending ping message at T = 0 for finding the RTT of all SFUs
    send(png,"SpltGate_o");
    EV << "[mfu" << getIndex() << "] Sending ping from MFU at = " << simTime() << endl;
}

void MFU::handleMessage(cMessage *msg)
{
    if(msg->isPacket() == true) {
        if(strcmp(msg->getName(),"gtc_hdr_ul") == 0) {        // updating buffer size after receiving requests from SFUs
            gtc_header *pkt = check_and_cast<gtc_header *>(msg);

            int sfuId = pkt->getSfuID();
            int index = sfuId % sfus;
            // for T-CONT 2
            sfu_buffer_TC2[index] = pkt->getBufferOccupancyTC2();
            EV << "[mfu" << getIndex() << "] updated sfu_buffer_TC2[" << sfuId << "] = " << sfu_buffer_TC2[sfuId] << endl;
            // for T-CONT 3
            sfu_buffer_TC3[index] = pkt->getBufferOccupancyTC3();
            EV << "[mfu" << getIndex() << "] updated sfu_buffer_TC3[" << sfuId << "] = " << sfu_buffer_TC3[sfuId] << endl;

            delete pkt;         // nothing more to do with the header
        }
        else if(strcmp(msg->getName(),"bkg_data") == 0) {        // updating buffer size after receiving requests from SFUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            int sfuId = pkt->getSfuId();
            int tcId = pkt->getTContId();
            pkt->setMfuId(getIndex());
            pkt->setSfuId(sfuId);
            send(pkt,"OnuGate_out");                     // just forward to ONU

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"xr_data") == 0) {        // updating buffer size after receiving requests from SFUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            int sfuId = pkt->getSfuId();
            int tcId = pkt->getTContId();
            pkt->setMfuId(getIndex());
            pkt->setSfuId(sfuId);
            send(pkt,"OnuGate_out");                     // just forward to ONU

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"hmd_data") == 0) {        // updating buffer size after receiving requests from SFUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            int sfuId = pkt->getSfuId();
            int tcId = pkt->getTContId();
            pkt->setMfuId(getIndex());
            pkt->setSfuId(sfuId);
            send(pkt,"OnuGate_out");                     // just forward to ONU

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"control_data") == 0) {        // updating buffer size after receiving requests from SFUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            int sfuId = pkt->getSfuId();
            int tcId = pkt->getTContId();
            pkt->setMfuId(getIndex());
            pkt->setSfuId(sfuId);
            send(pkt,"OnuGate_out");                     // just forward to ONU

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"haptic_data") == 0) {        // updating buffer size after receiving requests from SFUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            int sfuId = pkt->getSfuId();
            int tcId = pkt->getTContId();
            pkt->setMfuId(getIndex());
            pkt->setSfuId(sfuId);
            send(pkt,"OnuGate_out");                     // just forward to ONU

            //delete pkt;
        }
    }
    else {
        if(strcmp(msg->getName(),"ping") == 0) {
            ping_count += 1;
            ping *png = check_and_cast<ping *>(msg);
            int sfu_id = png->getSFU_id();
            int adj_fct = getIndex()*sfus;
            EV << "[mfu" << getIndex() << "] adj_fct = " << adj_fct << endl;
            sfu_rtt[sfu_id-adj_fct] = png->getArrivalTime().dbl();

            EV << "[mfu" << getIndex() << "] Received ping response from SFU-" << sfu_id << " and RTT = " << sfu_rtt[sfu_id-adj_fct] << endl;
            EV << "[mfu" << getIndex() << "] sfu_rtt[0] = " << sfu_rtt[0] << ", sfu_rtt[1] = " << sfu_rtt[1] << endl;
            //EV << "[mfu" << getIndex() << "] onu_rtt[2] = " << onu_rtt[2] << ", onu_rtt[3] = " << onu_rtt[3] << endl;

            if(ping_count == sfus) {
                //EV << "[mfu" << getIndex() << "] onu_total_latency[0] = " << onu_total_latency[0] << ", onu_total_latency[1] = " << onu_total_latency[1] << endl;
                cMessage *schedule_dl_gtc = new cMessage("schedule_dl_gtc");
                scheduleAt(simTime(), schedule_dl_gtc);           // when ping from all SFUs arrive, initiate the grant scheduling process

                sfu_max_grant = floor((max_polling_cycle - T_guard*sfus)*(int_pon_link_datarate/sfus)/8);  // in Bytes
                //EV << "[mfu" << getIndex() << "] worst_rtt = " << worst_rtt << ", onu_max_grant = " << onu_max_grant << endl;
                for(int i = 0;i<sfus;i++) {
                    sfu_grant_TC3[i]  = sfu_max_grant;       // initializing all SFUs with maximum grant value
                    sfu_buffer_TC3[i] = sfu_max_grant;
                }
            }
            delete png;
        }
        else if(strcmp(msg->getName(),"schedule_dl_gtc") == 0) {        // calculating the time-instants for sending grants to sfus
            scheduleAt(simTime()+(simtime_t)125e-6, msg);                          // schedule the self-message after 125 usec

            gtc_header *gtc_hdr_dl = new gtc_header("gtc_hdr_dl");
            gtc_hdr_dl->setMfuID(getIndex());
            double us_bw_map_sz = sfus*8;                                  // (N x 8) Bytes
            double gtc_hdr_sz = 4 + 4 + 13 + 1 + (4*2) + us_bw_map_sz;     // total size of GTC DL header
            //EV << "[mfu" << getIndex() << "] total GTC DL Header size = " << gtc_hdr_sz << endl;
            gtc_hdr_dl->setByteLength(gtc_hdr_sz);
            gtc_hdr_dl->setDownlink(true);
            gtc_hdr_dl->setInt_pon(true);
            gtc_hdr_dl->setSeqID(++seqID);
            gtc_hdr_dl->setMfu_sfu_rttArraySize(sfus);
            for (int i = 0; i < sfus; ++i) {
                gtc_hdr_dl->setMfu_sfu_rtt(i, sfu_rtt[i]);
            }

            gtc_hdr_dl->setSfu_start_time_TC2ArraySize(sfus);
            gtc_hdr_dl->setSfu_grant_TC2ArraySize(sfus);
            gtc_hdr_dl->setSfu_start_time_TC3ArraySize(sfus);
            gtc_hdr_dl->setSfu_grant_TC3ArraySize(sfus);

            double worst_rtt = *std::max_element(sfu_rtt.begin(), sfu_rtt.end());
            double tx_start = 0;
            double sfu_max_grant_TC2 = 0;
            double sfu_max_grant_TC3 = sfu_max_grant;

            for(int i = 0;i<sfus;i++) {
                if((sfu_buffer_TC2[i] > 0)||(sfu_buffer_TC3[i] > 0)) {                     // adjust priorities if TC-2 traffic is present
                    sfu_max_grant_TC2 = (sfu_buffer_TC2[i]/(sfu_buffer_TC2[i]+sfu_buffer_TC3[i]))*sfu_max_grant;
                    sfu_max_grant_TC3 = (1-(sfu_buffer_TC2[i]/(sfu_buffer_TC2[i]+sfu_buffer_TC3[i])))*sfu_max_grant;
                }

                sfu_grant_TC2[i] = std::min(sfu_buffer_TC2[i], sfu_max_grant_TC2);      // granting BW using limited service policy
                sfu_grant_TC3[i] = std::min(sfu_buffer_TC3[i], sfu_max_grant_TC3);
                //sfu_grant_TC2[i] = sfu_max_grant/2;                             // granting BW using fixed service policy
                //sfu_grant_TC3[i] = sfu_max_grant/2;

                // filling into the header packet for T-CONT 2
                sfu_start_time_TC2[i] = tx_start + T_guard;
                gtc_hdr_dl->setSfu_start_time_TC2(i, sfu_start_time_TC2[i]);
                gtc_hdr_dl->setSfu_grant_TC2(i, sfu_grant_TC2[i]);
                // filling into the header packet for T-CONT 3
                sfu_start_time_TC3[i] = tx_start + T_guard + (sfu_grant_TC2[i]*8/int_pon_link_datarate);
                gtc_hdr_dl->setSfu_start_time_TC3(i, sfu_start_time_TC3[i]);
                gtc_hdr_dl->setSfu_grant_TC3(i, sfu_grant_TC3[i]);
                // shifting the tx_start cursor
                tx_start += T_guard + (sfu_grant_TC2[i]*8/int_pon_link_datarate) + (sfu_grant_TC3[i]*8/int_pon_link_datarate);

                EV << "[mfu" << getIndex() << "] sfu_start_time_TC2[" << i << "] = " << simTime().dbl()+2*125e-6+sfu_start_time_TC2[i]-(worst_rtt/2) << " for seqID = " << seqID << endl;
                EV << "[mfu" << getIndex() << "] sfu_start_time_TC3[" << i << "] = " << simTime().dbl()+2*125e-6+sfu_start_time_TC3[i]-(worst_rtt/2) << " for seqID = " << seqID << endl;
            }
            EV << "[mfu" << getIndex() << "] last SFU tx finish time = " << simTime().dbl()+2*125e-6+sfu_start_time_TC3[sfus-1]-(worst_rtt/2)+(sfu_grant_TC3[sfus-1]*8/int_pon_link_datarate) << " for seqID = " << seqID << endl;

            send(gtc_hdr_dl,"SpltGate_o");          // sending the downlink GTC header to SFUs

            cMessage *send_dl_payload = new cMessage("send_dl_payload");    // send downlink data
            scheduleAt(simTime(), send_dl_payload);

        }
        else if(strcmp(msg->getName(),"send_dl_payload") == 0) {        // sending the downlink GTC header to SFUs
            delete msg;         // not doing anything now, just keeping the provision for future
        }
    }
}





