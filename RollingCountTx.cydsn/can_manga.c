/* ========================================
 * Can API for FRUCD
 * Schuyler Alschuler 2016 - 2017
 * ========================================
*/

#include "CAN_1.h"
#include "can_manga.h"

extern volatile uint32_t pedalOK;

volatile uint8_t VAL = 0;


uint8_t getVal()
{
    return VAL;
}

void can_receive(uint8_t *msg, int ID)
{
    uint8 InterruptState = CyEnterCriticalSection();
    
    uint8_t data[8];
    int i = 0;
    for (i = 0; i < 8; i++)
        data[i] = msg[i];
        
    switch (ID) 
    {
        case 0x001: // Curtis Status
            VAL = msg[CAN_1_DATA_BYTE_1];
            break;
    }
    
    CyExitCriticalSection(InterruptState);
}

void can_test_send()
{
    //CAN_1_DATA_BYTES_MSG msg;
    CAN_1_TX_MSG HeartB;
    
    HeartB.id = 0x300;
    HeartB.rtr = 0;
    HeartB.ide = 0;
    HeartB.dlc = 1;
    
    HeartB.irq = 0;
    
    HeartB.msg->byte[0] = (uint8) 1;
    HeartB.msg->byte[1] = (uint8) 1;
    HeartB.msg->byte[2] = (uint8) 1;
    HeartB.msg->byte[3] = (uint8) 1;
    HeartB.msg->byte[4] = (uint8) 1;
    HeartB.msg->byte[5] = (uint8) 1;
    HeartB.msg->byte[6] = (uint8) 1;
    HeartB.msg->byte[7] = (uint8) 1;
    
    CAN_1_SendMsg(&HeartB);
}

void can_send(uint8_t data[8], uint32_t ID)
{
    uint8_t i;
	CAN_1_TX_MSG message;
	CAN_1_DATA_BYTES_MSG payload;
	message.id = ID; 
	message.rtr = 0;
	message.ide = 0;
	message.dlc = 0x08;
	message.irq = 0;
	message.msg = &payload;
	for(i=0;i<8;i++)
		payload.byte[i] = data[i];
	CAN_1_SendMsg(&message); 
}
