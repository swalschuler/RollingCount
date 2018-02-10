/* ========================================
 * CAN BUS Transmission Firmware
 * Schuyler Alschuler (FRUCD)
 * ========================================
*/
#include <project.h>
#include "can_manga.h"
uint8 Tx_Data = 0x0;

int main()
{
    CAN_1_Start();

    CyGlobalIntEnable;
    uint8_t data[8] = {0x00,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    for(;;) /* do forever */
    {    
        LED_Write(~LED_Read());
        can_send(data, 0x001);
        CyDelay(1000);
        data[0]++;
    }
    
    return 0;
}
