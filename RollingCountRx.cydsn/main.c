
/* ========================================
 * CAN BUS Transmission Firmware
 * Schuyler Alschuler (FRUCD)
 * ========================================
*/

#include <project.h>
#include "can_manga.h"
uint8 Rx_Data = 0;

int main()
{
    LED_Write(1);
    CyDelay(500);
    LED_Write(0);
    CAN_1_Start();
    RCountTimer_Start();
    RCountISR_Start();
    
    CyGlobalIntEnable;

    for(;;) /* do forever */
    {  
        continue;
    }
    
    return 0;
}
