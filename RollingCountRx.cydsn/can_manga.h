/* ========================================
 * Can API for FRUCD
 * Schuyler Alschuler 2016 - 2017
 * ========================================
*/

#ifndef CAN_MANGA_H
#define CAN_MANGA_H

#include "CAN_1.h"

// Basic CAN functionality
void can_receive(uint8_t *msg, int ID);
void can_test_send();
void can_send(uint8_t data[8], uint32_t ID);

// Advanced CAN functionality
void can_send_cmd(uint8_t SetInterlock);
void can_send_status(uint8_t state, uint8_t errorState);

uint8_t getVal();

#endif

