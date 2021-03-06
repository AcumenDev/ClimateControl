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
LIBS:climate_control
LIBS:power_switches-cache
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
L MOC3063M U1
U 1 1 596A6E9F
P 3800 3550
F 0 "U1" H 3600 3750 50  0000 L CNN
F 1 "MOC3063M" H 3800 3750 50  0000 L CNN
F 2 "Housings_DIP:DIP-6_W7.62mm" H 3600 3350 50  0000 L CIN
F 3 "" H 3790 3550 50  0000 L CNN
	1    3800 3550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 596A7123
P 4550 3350
F 0 "R2" V 4630 3350 50  0000 C CNN
F 1 "220" V 4550 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 4480 3350 50  0001 C CNN
F 3 "" H 4550 3350 50  0000 C CNN
	1    4550 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 3600 4100 3600
Wire Wire Line
	4100 3600 4100 3650
Wire Wire Line
	4700 3350 5000 3350
Wire Wire Line
	5000 3350 5000 3800
Wire Wire Line
	5000 3800 5700 3800
Wire Wire Line
	5250 3800 5250 3650
Wire Wire Line
	4100 3450 4400 3450
Wire Wire Line
	4400 3450 4400 3350
$Comp
L R R1
U 1 1 596A71C3
P 3050 3450
F 0 "R1" V 3130 3450 50  0000 C CNN
F 1 "100" V 3050 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 2980 3450 50  0000 C CNN
F 3 "" H 3050 3450 50  0000 C CNN
	1    3050 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 3450 3200 3450
$Comp
L CP_Small C1
U 1 1 596A7243
P 2600 3550
F 0 "C1" H 2610 3620 50  0000 L CNN
F 1 "10u" H 2610 3470 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 2600 3550 50  0001 C CNN
F 3 "" H 2600 3550 50  0000 C CNN
	1    2600 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 3450 2900 3450
Wire Wire Line
	2350 3650 3500 3650
$Comp
L Screw_Terminal_1x02 J1
U 1 1 596A72C0
P 4900 2300
F 0 "J1" H 4900 2550 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 4750 2300 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_2pol" H 4900 2075 50  0001 C CNN
F 3 "" H 4875 2300 50  0001 C CNN
	1    4900 2300
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x02 J2
U 1 1 596A735F
P 5800 2300
F 0 "J2" H 5800 2550 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 5650 2300 50  0000 C TNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_2pol" H 5800 2075 50  0001 C CNN
F 3 "" H 5775 2300 50  0001 C CNN
	1    5800 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 3800 5700 3300
Connection ~ 5250 3800
$Comp
L BTA140-600 D1
U 1 1 596A7C62
P 5250 3500
F 0 "D1" H 5375 3525 50  0000 L CNN
F 1 "BTA140-600" H 5375 3450 50  0000 L CNN
F 2 "Power_Integrations:TO-220" V 5325 3525 50  0000 C CNN
F 3 "" V 5250 3500 50  0000 C CNN
	1    5250 3500
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 596A835D
P 2150 3550
F 0 "P1" H 2150 3700 50  0000 C CNN
F 1 "CONN_01X02" V 2250 3550 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x02_Pitch2.54mm" H 2150 3550 50  0001 C CNN
F 3 "" H 2150 3550 50  0000 C CNN
	1    2150 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2350 3450 2350 3500
Connection ~ 2600 3450
Wire Wire Line
	2350 3650 2350 3600
Connection ~ 2600 3650
Wire Wire Line
	5000 2500 5000 2650
Wire Wire Line
	5000 2650 5700 2650
Wire Wire Line
	5700 2650 5700 2500
Wire Wire Line
	5250 3350 5250 3000
Wire Wire Line
	5250 3000 4800 3000
Wire Wire Line
	4800 3000 4800 2500
Wire Wire Line
	5700 3300 5900 3300
Wire Wire Line
	5900 3300 5900 2500
$EndSCHEMATC
