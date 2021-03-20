
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
#include "nlib\StringFormat\stringformat.h"
#include "nlib\StringSerial\stringserial.h"
#include "nlib\OLEDisplay\OLEDisplay.h"

// -*-*- List of node objects -*-*-
nBlock_Ticker            nb_nBlockNode1_Ticker       (1000);
nBlock_Thermistor        nb_nBlockNode2_Thermistor   (p20, 10000, 100000, 25, 4267);
nBlock_PID               nb_nBlockNode3_PID          (0.01, 0.01, 0.0, 1.0, 0.0, 1.0, AUTOMATIC, DIRECT, 30.0);
nBlock_PWM               nb_nBlockNode4_PWM          (LED3, 1000);
nBlock_StringFormat      nb_nBlockNode5_StringFormat ("pid_OUT = %d\n");
nBlock_StringSerial      nb_nBlockNode6_StringSerial (USBTX, USBRX);
nBlock_StringFormat      nb_nBlockNode7_StringFormat ("Temp = %3.1f \r");
nBlock_OLEDisplay        nb_nBlockNode8_OLEDisplay   (p9, p10, p27);

// -*-*- List of connection objects -*-*-
nBlockConnection    n_conn0( &nb_nBlockNode7_StringFormat, 0,    &nb_nBlockNode8_OLEDisplay,   0);
nBlockConnection    n_conn1( &nb_nBlockNode5_StringFormat, 0,    &nb_nBlockNode6_StringSerial, 0);
nBlockConnection    n_conn2( &nb_nBlockNode3_PID,          0,    &nb_nBlockNode4_PWM,          0);
nBlockConnection    n_conn3( &nb_nBlockNode3_PID,          0,    &nb_nBlockNode5_StringFormat, 0);
nBlockConnection    n_conn4( &nb_nBlockNode2_Thermistor,   0,    &nb_nBlockNode3_PID,          0);
nBlockConnection    n_conn5( &nb_nBlockNode2_Thermistor,   0,    &nb_nBlockNode7_StringFormat, 0);
nBlockConnection    n_conn6( &nb_nBlockNode1_Ticker,       0,    &nb_nBlockNode2_Thermistor,   0);


// -*-*- Main function -*-*-
int main(void) {
    SetupWorkbench();
    while(1) {
        ProgressNodes();
        
        // Your custom code here!
    }
}