# [38D_PID_test](https://github.com/nBlocksStudioApps/38D_PID_test_FIRMWARE)

Testing program translated from schematic Design [38D_PID_test_SCHEMATIC
](https://github.com/nBlocksStudioApps/38D_PID_test_SCHEMATIC) for the Node [PID](https://github.com/nBlocksStudioNodes/nblocks_pid), controlling a heating element with a PWM driven power MOSFET and a Thermistor for sensing element.



## nBlocksStudio Schematic Design


<p align="center">
<img
src="img/01.PNG"
width = 800
/>
</p>

----

## Setup

>  Left: Hot End and thermocouple probe  
>  Middle: n-3DP board  
>  Right: Overall setup

----

<img
src="img/06.PNG"
width = 300
/>
<img
src="img/04.GIF"
height = 300
/>


----


## Temperature controll results

>  Left: Stabilized temeprature at 60 °C measured by Thermistor  
>  Middle: Temeperature measured with an external Thermocouple probe  
>  Right: Current consumption is stabilized at 163 mA
----

<img
src="img/02.GIF"
height = 250
/>
<img
src="img/05.GIF"
height = 250
/>
<img
src="img/07.PNG"
height = 250
/>

----


## Thermistor Node

Thermistor Node with an added debugging printf(), prints the ADC value for the temperature value it exports. 
<p align="center">
<img
src="img/15.PNG"
height = 350
/>
<img
src="img/09.GIF"
height = 350
/>
</p>

----

The formula used in the Node C++ code is validated and confirmed using and excel spreadsheet and online Thermistor calculators. The theoretical Temperature value for the corresponding ADC measurement is precise. Measuring with the Multimeter indicates a slight difference from the measured voltage from ADC. 

### Conclusion on Thermistor Node precision
The Thermistor Node works good, the ADC Hardware front-end needs some improvement, but the precision is still good for a hot-end temperature control.

----

<img
src="img/13.PNG"
width = 900
/>

----

## PID control evaluation

----

<img
src="img/10.PNG"
width = 900
/>


After trial and error, the values below result an acceptable controlling performance
*  P = 0.2 
*  I = 0.025 
*  D = 0 
*  SamplingTime = 0.2 sec
*  minOutput = 0
*  maxOutput = 1
*  setPoint = 60 °C 

----

Powered-on at a temperature 40 °C, the PID controller tries to fix the temperature to the 60 °C set point fast, so we have an overshoot, then the system is stabilized with a slight oscillation around the 60 °C value. 

<p align="center">
<img
src="img/14.GIF"
width = 900
/>
</p>

Plotted with Arduino plotter.

----