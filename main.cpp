
/* ================================================================ *
 *          Automatically generated by n-Blocks Studio 2.0          *
 *                                                                  *
 *                         www.n-blocks.net                         *
 * ================================================================ */
#include "nlib\nblocks.h"
// #include "nlib\BSP\bsp.h"
// Custom nodes:
#include "nlib\KernelFramePulse\kernelframepulse.h"
#include "nlib\Ticker\ticker.h"
#include "nlib\Thermistor\thermistor.h"
#include "nlib\PID\PID.h"
#include "nlib\PWM\pwm.h"
#include "nlib\StringSerial\stringserial.h"
#include "nlib\StringFormat\stringformat.h"

// -*-*- List of node objects -*-*-
nBlock_KernelFramePulse      nb_nBlockNode1_KernelFramePulse (LED2);
nBlock_Ticker                nb_nBlockNode2_Ticker           (200);
nBlock_Thermistor            nb_nBlockNode3_Thermistor       (P0_24, 4700, 100000, 25, 4267);
nBlock_PID                   nb_nBlockNode4_PID              (0.2, 0.025, 0.0, 0.2, 0.0, 1.0, AUTOMATIC, DIRECT, 60.0);
nBlock_PWM                   nb_nBlockNode5_PWM              (P2_5, 100);
nBlock_StringSerial          nb_nBlockNode6_StringSerial     (USBTX, USBRX);
nBlock_StringFormat          nb_nBlockNode7_StringFormat     ("Temp = %3.1f \r\n");

// -*-*- List of connection objects -*-*-
nBlockConnection    n_conn0( &nb_nBlockNode7_StringFormat,     0,    &nb_nBlockNode6_StringSerial,     0);
nBlockConnection    n_conn1( &nb_nBlockNode4_PID,              0,    &nb_nBlockNode5_PWM,              0);
nBlockConnection    n_conn2( &nb_nBlockNode3_Thermistor,       0,    &nb_nBlockNode4_PID,              0);
nBlockConnection    n_conn3( &nb_nBlockNode3_Thermistor,       0,    &nb_nBlockNode7_StringFormat,     0);
nBlockConnection    n_conn4( &nb_nBlockNode2_Ticker,           0,    &nb_nBlockNode3_Thermistor,       0);


// -*-*- Main function -*-*-
int main(void) {
    SetupWorkbench();
    while(1) {
        ProgressNodes();
        
        // Your custom code here!
    }
}
