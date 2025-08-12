/*
 * wifi_ap.cc
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

class WiFi_AP : public cSimpleModule
{
    private:
        //cQueue wap_queue;

    public:
        //virtual ~WiFi_AP();

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

Define_Module(WiFi_AP);

void WiFi_AP::initialize()
{
    //olt_queue.setName("olt_queue");

    gate("Sfu_in")->setDeliverImmediately(true);
    gate("SrcXr_in")->setDeliverImmediately(true);
    gate("SrcHmd_in")->setDeliverImmediately(true);
    gate("SrcHpt_in")->setDeliverImmediately(true);
    gate("SrcCtr_in")->setDeliverImmediately(true);
    gate("SrcBkg1_in")->setDeliverImmediately(true);
    gate("SrcBkg2_in")->setDeliverImmediately(true);
    gate("SrcBkg3_in")->setDeliverImmediately(true);
}

void WiFi_AP::handleMessage(cMessage *msg)
{
    if(msg->isPacket() == true) {
        if(strcmp(msg->getName(),"bkg_data") == 0) {        // updating buffer size after receiving requests from ONUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            pkt->setWapArrivalTime(pkt->getArrivalTime());
            send(pkt,"Sfu_out");                            // just forward to SFU
            pkt->setWapDepartureTime(pkt->getSendingTime());

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"xr_data") == 0) {        // updating buffer size after receiving requests from ONUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            pkt->setWapArrivalTime(pkt->getArrivalTime());
            send(pkt,"Sfu_out");                            // just forward to SFU
            pkt->setWapDepartureTime(pkt->getSendingTime());

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"hmd_data") == 0) {        // updating buffer size after receiving requests from ONUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            pkt->setWapArrivalTime(pkt->getArrivalTime());
            send(pkt,"Sfu_out");                            // just forward to SFU
            pkt->setWapDepartureTime(pkt->getSendingTime());

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"control_data") == 0) {        // updating buffer size after receiving requests from ONUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            pkt->setWapArrivalTime(pkt->getArrivalTime());
            send(pkt,"Sfu_out");                            // just forward to SFU
            pkt->setWapDepartureTime(pkt->getSendingTime());

            //delete pkt;
        }
        else if(strcmp(msg->getName(),"haptic_data") == 0) {        // updating buffer size after receiving requests from ONUs
            ethPacket *pkt = check_and_cast<ethPacket *>(msg);

            pkt->setWapArrivalTime(pkt->getArrivalTime());
            send(pkt,"Sfu_out");                            // just forward to SFU
            pkt->setWapDepartureTime(pkt->getSendingTime());

            //delete pkt;
        }
    }
    else {
        EV << "[wap" << getIndex() << "] Some unknown cMessage has arrived at = " << simTime() << endl;
    }
}





