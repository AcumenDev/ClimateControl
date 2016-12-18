EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:climat-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SW_PUSH SW1
U 1 1 57DC32CA
P 3900 2350
F 0 "SW1" H 4050 2460 50  0000 C CNN
F 1 "SW_PUSH" H 3900 2270 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 3900 2350 50  0001 C CNN
F 3 "" H 3900 2350 50  0000 C CNN
	1    3900 2350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW2
U 1 1 57DC331F
P 3900 3050
F 0 "SW2" H 4050 3160 50  0000 C CNN
F 1 "SW_PUSH" H 3900 2970 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 3900 3050 50  0001 C CNN
F 3 "" H 3900 3050 50  0000 C CNN
	1    3900 3050
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 57DC3388
P 3900 3600
F 0 "SW3" H 4050 3710 50  0000 C CNN
F 1 "SW_PUSH" H 3900 3520 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 3900 3600 50  0001 C CNN
F 3 "" H 3900 3600 50  0000 C CNN
	1    3900 3600
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW4
U 1 1 57DC33BF
P 3900 4400
F 0 "SW4" H 4050 4510 50  0000 C CNN
F 1 "SW_PUSH" H 3900 4320 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 3900 4400 50  0001 C CNN
F 3 "" H 3900 4400 50  0000 C CNN
	1    3900 4400
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW5
U 1 1 57DC3424
P 3900 4950
F 0 "SW5" H 4050 5060 50  0000 C CNN
F 1 "SW_PUSH" H 3900 4850 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_SMALL" H 3900 4950 50  0001 C CNN
F 3 "" H 3900 4950 50  0000 C CNN
	1    3900 4950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P1
U 1 1 57DC368A
P 2550 3350
F 0 "P1" H 2550 3700 50  0000 C CNN
F 1 "CONN_01X06" V 2650 3350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 2550 3350 50  0001 C CNN
F 3 "" H 2550 3350 50  0000 C CNN
	1    2550 3350
	-1   0    0    1   
$EndComp
Wire Wire Line
	3600 2350 2750 2350
Wire Wire Line
	2750 2350 2750 3100
Wire Wire Line
	3600 3050 3150 3050
Wire Wire Line
	3150 3050 3150 3200
Wire Wire Line
	3150 3200 2750 3200
Wire Wire Line
	3600 3600 3600 3300
Wire Wire Line
	3600 3300 2750 3300
Wire Wire Line
	3600 4400 3350 4400
Wire Wire Line
	3350 4400 3350 3400
Wire Wire Line
	3350 3400 2750 3400
Wire Wire Line
	3600 4950 3150 4950
Wire Wire Line
	3150 4950 3150 3500
Wire Wire Line
	3150 3500 2750 3500
Wire Wire Line
	2750 3600 2950 3600
Wire Wire Line
	2950 3600 2950 5250
Wire Wire Line
	2950 5250 4500 5250
Wire Wire Line
	4500 5250 4500 2350
Wire Wire Line
	4500 2350 4200 2350
Wire Wire Line
	4200 3050 4500 3050
Connection ~ 4500 3050
Wire Wire Line
	4200 3600 4500 3600
Connection ~ 4500 3600
Wire Wire Line
	4200 4400 4500 4400
Connection ~ 4500 4400
Wire Wire Line
	4200 4950 4500 4950
Connection ~ 4500 4950
$EndSCHEMATC
