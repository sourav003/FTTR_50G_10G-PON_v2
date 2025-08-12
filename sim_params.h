/*
 * sim_params.h
 *
 *  Created on: 30 July 2025
 *      Author: mondals
 */

#ifndef SIM_PARAMS_H_
#define SIM_PARAMS_H_

extern double olt_onu_distance;               // OLT-ONU distance (km)
extern double light_speed;                    // speed of light in fiber 2 x 10^5 km/s
extern double ext_pon_link_datarate;          // External PON link datarate = 50 Gbps
extern double int_pon_link_datarate;          // Internal PON link datarate = 10 Gbps
extern double max_polling_cycle;              // maximum polling cycle duration

extern int const pkt_sz_min;                  // Ethernet packet size - minimum (bytes)
extern int const pkt_sz_max;                  // Ethernet packet size - maximum (bytes)
extern int pkt_sz_avg;                        // Average packet size (bytes)

extern double onu_buffer_capacity;            // ONU buffer capacity (bytes)
extern double sfu_buffer_capacity;            // SFU buffer capacity (bytes)
extern double T_guard;                        // guard time for each ONU


#endif /* SIM_PARAMS_H_ */
