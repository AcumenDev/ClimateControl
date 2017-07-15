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
P 3900 3900
F 0 "U1" H 3700 4100 50  0000 L CNN
F 1 "MOC3063M" H 3900 4100 50  0000 L CNN
F 2 "Housings_DIP:DIP-6_W7.62mm" H 3700 3700 50  0000 L CIN
F 3 "" H 3890 3900 50  0000 L CNN
	1    3900 3900
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 596A7123
P 4650 3700
F 0 "R2" V 4730 3700 50  0000 C CNN
F 1 "220" V 4650 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4580 3700 50  0001 C CNN
F 3 "" H 4650 3700 50  0000 C CNN
	1    4650 3700
	0    1    1    0   
$EndComp
Wire Wire Line
	5200 3950 4200 3950
Wire Wire Line
	4200 3950 4200 4000
Wire Wire Line
	4800 3700 5100 3700
Wire Wire Line
	5100 3700 5100 4150
Wire Wire Line
	5100 4150 5800 4150
Wire Wire Line
	5350 4150 5350 4000
Wire Wire Line
	4200 3800 4500 3800
Wire Wire Line
	4500 3800 4500 3700
$Comp
L R R1
U 1 1 596A71C3
P 3150 3800
F 0 "R1" V 3230 3800 50  0000 C CNN
F 1 "1k" V 3150 3800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3080 3800 50  0000 C CNN
F 3 "" H 3150 3800 50  0000 C CNN
	1    3150 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 3800 3300 3800
$Comp
L CP_Small C1
U 1 1 596A7243
P 2700 3900
F 0 "C1" H 2710 3970 50  0000 L CNN
F 1 "10u" H 2710 3820 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 2700 3900 50  0001 C CNN
F 3 "" H 2700 3900 50  0000 C CNN
	1    2700 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3800 3000 3800
Wire Wire Line
	2450 4000 3600 4000
$Comp
L Screw_Terminal_1x02 J1
U 1 1 596A72C0
P 6000 3100
F 0 "J1" H 6000 3350 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 5850 3100 50  0000 C TNN
F 2 "Connectors:AK300-2" H 6000 2875 50  0001 C CNN
F 3 "" H 5975 3100 50  0001 C CNN
	1    6000 3100
	-1   0    0    1   
$EndComp
$Comp
L Screw_Terminal_1x02 J2
U 1 1 596A735F
P 6000 3550
F 0 "J2" H 6000 3800 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 5850 3550 50  0000 C TNN
F 2 "Connectors:AK300-2" H 6000 3325 50  0001 C CNN
F 3 "" H 5975 3550 50  0001 C CNN
	1    6000 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	5800 3200 5650 3200
Wire Wire Line
	5650 3200 5650 3450
Wire Wire Line
	5650 3450 5800 3450
Wire Wire Line
	5800 3000 5350 3000
Wire Wire Line
	5350 3000 5350 3700
Wire Wire Line
	5800 4150 5800 3650
Connection ~ 5350 4150
$Comp
L BTA140-600 D1
U 1 1 596A7C62
P 5350 3850
F 0 "D1" H 5475 3875 50  0000 L CNN
F 1 "BTA140-600" H 5475 3800 50  0000 L CNN
F 2 "Power_Integrations:TO-220" V 5425 3875 50  0000 C CNN
F 3 "" V 5350 3850 50  0000 C CNN
	1    5350 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 596A835D
P 2250 3900
F 0 "P1" H 2250 4050 50  0000 C CNN
F 1 "CONN_01X02" V 2350 3900 50  0000 C CNN
F 2 "Connectors_Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_2pol" H 2250 3900 50  0001 C CNN
F 3 "" H 2250 3900 50  0000 C CNN
	1    2250 3900
	-1   0    0    1   
$EndComp
Wire Wire Line
	2450 3800 2450 3850
Connection ~ 2700 3800
Wire Wire Line
	2450 4000 2450 3950
Connection ~ 2700 4000
$EndSCHEMATC