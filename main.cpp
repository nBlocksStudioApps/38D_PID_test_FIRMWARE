
/* ================================================================ *
 *          Automatically generated by n-Blocks Studio 2.0          *
 *                                                                  *
 *                         www.n-blocks.net                         *
 * ================================================================ */
#include "nlib\nblocks.h"
// #include "nlib\BSP\bsp.h"
// Custom nodes:
#include "nlib\Ticker\ticker.h"
#include "nlib\Thermistor\thermistor.h"
#include "nlib\PID\PID.h"
#include "nlib\PWM\pwm.h"
#include "nlib\StringSerial\stringserial.h"
#include "nlib\StringFormat\stringformat.h"

// -*-*- List of node objects -*-*-
nBlock_Ticker            nb_nBlockNode1_Ticker       (200);
nBlock_Thermistor        nb_nBlockNode2_Thermistor   (P0_24, 4700, 10000, 25, 4267);
nBlock_PID               nb_nBlockNode3_PID          (0.0001, 0.0001, 0.0, 0.2, 0.0, 1.0, AUTOMATIC, DIRECT, 60.0);
nBlock_PWM               nb_nBlockNode4_PWM          (P2_5, 100);
nBlock_StringSerial      nb_nBlockNode5_StringSerial (USBTX, USBRX);
nBlock_StringFormat      nb_nBlockNode6_StringFormat ("Temp = %3.1f \r");

// -*-*- List of connection objects -*-*-
nBlockConnection    n_conn0( &nb_nBlockNode6_StringFormat, 0,    &nb_nBlockNode5_StringSerial, 0);
nBlockConnection    n_conn1( &nb_nBlockNode3_PID,          0,    &nb_nBlockNode4_PWM,          0);
nBlockConnection    n_conn2( &nb_nBlockNode2_Thermistor,   0,    &nb_nBlockNode3_PID,          0);
nBlockConnection    n_conn3( &nb_nBlockNode2_Thermistor,   0,    &nb_nBlockNode6_StringFormat, 0);
nBlockConnection    n_conn4( &nb_nBlockNode1_Ticker,       0,    &nb_nBlockNode2_Thermistor,   0);


// -*-*- Main function -*-*-
int main(void) {
    SetupWorkbench();
    while(1) {
        ProgressNodes();
        
        // Your custom code here!
    }
}
