EESchema Schematic File Version 2
LIBS:tinkerforge
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
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Industrial Digital Out 4 2.0"
Date "2018-01-17"
Rev "1.0"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2018, L.Lauer <lukas@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 600  7700 0    39   ~ 0
Copyright Tinkerforge GmbH 2012.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
Connection ~ 10600 1950
Wire Wire Line
	10600 1950 10600 2550
Connection ~ 9850 1850
Wire Wire Line
	9850 1450 9850 1900
Wire Wire Line
	10300 1650 10300 1400
Wire Wire Line
	9500 1400 9500 1250
Wire Wire Line
	10650 1850 10650 800 
Wire Wire Line
	10650 800  9500 800 
Connection ~ 6600 950 
Wire Wire Line
	6600 950  6600 800 
Connection ~ 6550 950 
Connection ~ 6750 3150
Wire Wire Line
	6750 1350 6750 3150
Wire Wire Line
	6550 1350 6550 2150
Wire Wire Line
	6450 1500 7400 1500
Wire Wire Line
	7400 2600 6500 2600
Wire Wire Line
	10500 1950 10650 1950
Wire Wire Line
	10650 2350 9150 2350
Wire Wire Line
	9150 2350 9150 3250
Wire Wire Line
	9150 3250 8400 3250
Wire Wire Line
	8400 2150 10650 2150
Connection ~ 7000 950 
Wire Wire Line
	7200 950  6900 950 
Wire Wire Line
	8900 3900 8900 3800
Wire Wire Line
	8450 4850 8450 4750
Connection ~ 7100 3950
Wire Wire Line
	6900 3950 7200 3950
Wire Wire Line
	6450 2750 6450 3150
Connection ~ 7100 2250
Wire Wire Line
	7400 2250 7100 2250
Connection ~ 6900 3350
Wire Wire Line
	6900 1350 6900 3550
Wire Wire Line
	7000 3550 7000 1350
Wire Wire Line
	7100 1350 7100 3550
Wire Wire Line
	7200 3550 7200 1350
Wire Wire Line
	3600 2550 3750 2550
Wire Wire Line
	3750 2350 3600 2350
Wire Wire Line
	3600 2250 3750 2250
Wire Wire Line
	3750 2450 3600 2450
Wire Wire Line
	7400 3350 6900 3350
Wire Wire Line
	7400 1700 7200 1700
Connection ~ 7200 1700
Wire Wire Line
	7400 2800 7000 2800
Connection ~ 7000 2800
Wire Wire Line
	6500 2600 6500 2450
Wire Wire Line
	6500 2450 5850 2450
Connection ~ 7000 3950
Wire Wire Line
	7050 3950 7050 4150
Connection ~ 7050 3950
Wire Wire Line
	8450 3750 8450 3850
Wire Wire Line
	8500 3800 8450 3800
Connection ~ 8450 3800
Connection ~ 7100 950 
Wire Wire Line
	7050 950  7050 800 
Connection ~ 7050 950 
Wire Wire Line
	10650 2050 9000 2050
Wire Wire Line
	9000 2050 9000 1600
Wire Wire Line
	9000 1600 8400 1600
Wire Wire Line
	10650 2250 9000 2250
Wire Wire Line
	9000 2250 9000 2700
Wire Wire Line
	9000 2700 8400 2700
Wire Wire Line
	9500 800  9500 850 
Connection ~ 9850 800 
Wire Wire Line
	6450 3150 7400 3150
Wire Wire Line
	6450 1350 6450 1850
Connection ~ 6450 1500
Wire Wire Line
	6650 1350 6650 2600
Connection ~ 6650 2600
Wire Wire Line
	6750 950  6450 950 
Connection ~ 6650 950 
Wire Wire Line
	10100 1950 10000 1950
Wire Wire Line
	10000 1950 10000 1850
Wire Wire Line
	10000 1850 9850 1850
Wire Wire Line
	9850 800  9850 750 
Wire Wire Line
	10300 900  10300 800 
Connection ~ 10300 800 
Wire Wire Line
	10250 1450 10300 1450
Connection ~ 10300 1450
Wire Wire Line
	10600 2550 10650 2550
$Comp
L ZENER D1
U 1 1 5048CEF9
P 10050 1450
F 0 "D1" H 10050 1550 50  0000 C CNN
F 1 "Z12V" H 10050 1350 40  0000 C CNN
F 2 "MiniMelf" H 10050 1450 60  0001 C CNN
F 3 "" H 10050 1450 60  0001 C CNN
	1    10050 1450
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5048CD73
P 10300 1150
F 0 "R1" V 10380 1150 50  0000 C CNN
F 1 "100k" V 10300 1150 50  0000 C CNN
F 2 "R0603F" H 10300 1150 60  0001 C CNN
F 3 "" H 10300 1150 60  0001 C CNN
	1    10300 1150
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR01
U 1 1 5048CD61
P 9500 1400
F 0 "#PWR01" H 9500 1400 40  0001 C CNN
F 1 "AGND" H 9500 1250 50  0000 C CNN
F 2 "" H 9500 1400 60  0001 C CNN
F 3 "" H 9500 1400 60  0001 C CNN
	1    9500 1400
	1    0    0    -1  
$EndComp
$Comp
L MOSFET_N_CH Q1
U 1 1 5048CCEB
P 10300 1850
F 0 "Q1" H 10310 2020 60  0000 R CNN
F 1 "FDN5630" H 10310 1700 60  0000 R CNN
F 2 "SOT23GDS" H 10300 1850 60  0001 C CNN
F 3 "" H 10300 1850 60  0001 C CNN
	1    10300 1850
	0    1    1    0   
$EndComp
$Comp
L VPP #PWR02
U 1 1 5006BC37
P 6600 800
F 0 "#PWR02" H 6600 1000 40  0001 C CNN
F 1 "VPP" H 6600 950 40  0000 C CNN
F 2 "" H 6600 800 60  0001 C CNN
F 3 "" H 6600 800 60  0001 C CNN
	1    6600 800 
	1    0    0    -1  
$EndComp
$Comp
L R_PACK4 RP2
U 1 1 5006BBF0
P 6800 1150
F 0 "RP2" H 6800 1600 40  0000 C CNN
F 1 "12k" H 6800 1350 40  0000 C CNN
F 2 "1206X4" H 6800 1150 60  0001 C CNN
F 3 "" H 6800 1150 60  0001 C CNN
	1    6800 1150
	0    -1   -1   0   
$EndComp
$Comp
L CP1 C3
U 1 1 5006A494
P 9500 1050
F 0 "C3" H 9550 1150 50  0000 L CNN
F 1 "68µF/50V" V 9350 850 50  0000 L CNN
F 2 "ELKO_83" H 9500 1050 60  0001 C CNN
F 3 "" H 9500 1050 60  0001 C CNN
	1    9500 1050
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR03
U 1 1 5006A441
P 9850 1900
F 0 "#PWR03" H 9850 1900 40  0001 C CNN
F 1 "AGND" H 9850 1750 50  0000 C CNN
F 2 "" H 9850 1900 60  0001 C CNN
F 3 "" H 9850 1900 60  0001 C CNN
	1    9850 1900
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR04
U 1 1 5006A2EE
P 9850 750
F 0 "#PWR04" H 9850 950 40  0001 C CNN
F 1 "VPP" H 9850 900 40  0000 C CNN
F 2 "" H 9850 750 60  0001 C CNN
F 3 "" H 9850 750 60  0001 C CNN
	1    9850 750 
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR05
U 1 1 5006A265
P 7050 800
F 0 "#PWR05" H 7050 1000 40  0001 C CNN
F 1 "VPP" H 7050 950 40  0000 C CNN
F 2 "" H 7050 800 60  0001 C CNN
F 3 "" H 7050 800 60  0001 C CNN
	1    7050 800 
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR06
U 1 1 5006A25E
P 8900 3900
F 0 "#PWR06" H 8900 3900 40  0001 C CNN
F 1 "AGND" H 8900 3750 50  0000 C CNN
F 2 "" H 8900 3900 60  0001 C CNN
F 3 "" H 8900 3900 60  0001 C CNN
	1    8900 3900
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5006A251
P 8700 3800
F 0 "C2" H 8750 3900 50  0000 L CNN
F 1 "100nF" H 8750 3700 50  0000 L CNN
F 2 "C0805" H 8700 3800 60  0001 C CNN
F 3 "" H 8700 3800 60  0001 C CNN
	1    8700 3800
	0    -1   -1   0   
$EndComp
$Comp
L VPP #PWR07
U 1 1 5006A241
P 8450 3750
F 0 "#PWR07" H 8450 3950 40  0001 C CNN
F 1 "VPP" H 8450 3900 40  0000 C CNN
F 2 "" H 8450 3750 60  0001 C CNN
F 3 "" H 8450 3750 60  0001 C CNN
	1    8450 3750
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR08
U 1 1 5006A237
P 8450 4850
F 0 "#PWR08" H 8450 4850 40  0001 C CNN
F 1 "AGND" H 8450 4700 50  0000 C CNN
F 2 "" H 8450 4850 60  0001 C CNN
F 3 "" H 8450 4850 60  0001 C CNN
	1    8450 4850
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR09
U 1 1 5006A211
P 6350 4150
F 0 "#PWR09" H 6350 4150 40  0001 C CNN
F 1 "AGND" H 6350 4000 50  0000 C CNN
F 2 "" H 6350 4150 60  0001 C CNN
F 3 "" H 6350 4150 60  0001 C CNN
	1    6350 4150
	1    0    0    -1  
$EndComp
$Comp
L AGND #PWR010
U 1 1 5006A205
P 7050 4150
F 0 "#PWR010" H 7050 4150 40  0001 C CNN
F 1 "AGND" H 7050 4000 50  0000 C CNN
F 2 "" H 7050 4150 60  0001 C CNN
F 3 "" H 7050 4150 60  0001 C CNN
	1    7050 4150
	1    0    0    -1  
$EndComp
$Comp
L R_PACK4 RP4
U 1 1 5006A188
P 7250 3750
F 0 "RP4" H 7250 4200 40  0000 C CNN
F 1 "10k" H 7250 3700 40  0000 C CNN
F 2 "1206X4" H 7250 3750 60  0001 C CNN
F 3 "" H 7250 3750 60  0001 C CNN
	1    7250 3750
	0    -1   -1   0   
$EndComp
$Comp
L R_PACK4 RP3
U 1 1 5006A169
P 7250 1150
F 0 "RP3" H 7250 1100 40  0000 C CNN
F 1 "10k" H 7250 1350 40  0000 C CNN
F 2 "1206X4" H 7250 1150 60  0001 C CNN
F 3 "" H 7250 1150 60  0001 C CNN
	1    7250 1150
	0    -1   -1   0   
$EndComp
$Comp
L LMV344 U3
U 5 1 5006A0F8
P 8550 4300
F 0 "U3" H 8500 4500 60  0000 L CNN
F 1 "OPA4171AIDR" H 8500 4050 60  0000 L CNN
F 2 "SOP14" H 8550 4300 60  0001 C CNN
F 3 "" H 8550 4300 60  0001 C CNN
	5    8550 4300
	1    0    0    -1  
$EndComp
$Comp
L LMV344 U3
U 4 1 5006A0F2
P 7900 1600
F 0 "U3" H 7850 1800 60  0000 L CNN
F 1 "OPA4171AIDR" H 7850 1350 60  0000 L CNN
F 2 "SOP14" H 7900 1600 60  0001 C CNN
F 3 "" H 7900 1600 60  0001 C CNN
	4    7900 1600
	1    0    0    1   
$EndComp
$Comp
L LMV344 U3
U 3 1 5006A0EB
P 7900 2150
F 0 "U3" H 7850 2350 60  0000 L CNN
F 1 "OPA4171AIDR" H 7850 1900 60  0000 L CNN
F 2 "SOP14" H 7900 2150 60  0001 C CNN
F 3 "" H 7900 2150 60  0001 C CNN
	3    7900 2150
	1    0    0    1   
$EndComp
$Comp
L LMV344 U3
U 2 1 5006A0E5
P 7900 2700
F 0 "U3" H 7850 2900 60  0000 L CNN
F 1 "OPA4171AIDR" H 7850 2450 60  0000 L CNN
F 2 "SOP14" H 7900 2700 60  0001 C CNN
F 3 "" H 7900 2700 60  0001 C CNN
	2    7900 2700
	1    0    0    1   
$EndComp
$Comp
L LMV344 U3
U 1 1 5006A082
P 7900 3250
F 0 "U3" H 7850 3450 60  0000 L CNN
F 1 "OPA4171AIDR" H 7850 3000 60  0000 L CNN
F 2 "SOP14" H 7900 3250 60  0001 C CNN
F 3 "" H 7900 3250 60  0001 C CNN
	1    7900 3250
	1    0    0    1   
$EndComp
$Comp
L R_PACK4 RP1
U 1 1 50069EDD
P 3950 2600
F 0 "RP1" H 3950 3050 40  0000 C CNN
F 1 "1k" H 3950 2550 40  0000 C CNN
F 2 "0603X4" H 3950 2600 60  0001 C CNN
F 3 "" H 3950 2600 60  0001 C CNN
	1    3950 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 50066B39
P 1150 2800
F 0 "#PWR011" H 1150 2800 30  0001 C CNN
F 1 "GND" H 1150 2730 30  0001 C CNN
F 2 "" H 1150 2800 60  0001 C CNN
F 3 "" H 1150 2800 60  0001 C CNN
	1    1150 2800
	1    0    0    -1  
$EndComp
$Comp
L DRILL U5
U 1 1 5006691C
P 10600 6350
F 0 "U5" H 10650 6400 60  0001 C CNN
F 1 "DRILL" H 10600 6350 60  0000 C CNN
F 2 "DRILL_NP" H 10600 6350 60  0001 C CNN
F 3 "" H 10600 6350 60  0001 C CNN
	1    10600 6350
	1    0    0    -1  
$EndComp
$Comp
L DRILL U4
U 1 1 5006691A
P 10600 6100
F 0 "U4" H 10650 6150 60  0001 C CNN
F 1 "DRILL" H 10600 6100 60  0000 C CNN
F 2 "DRILL_NP" H 10600 6100 60  0001 C CNN
F 3 "" H 10600 6100 60  0001 C CNN
	1    10600 6100
	1    0    0    -1  
$EndComp
$Comp
L DRILL U6
U 1 1 50066918
P 10950 6100
F 0 "U6" H 11000 6150 60  0001 C CNN
F 1 "DRILL" H 10950 6100 60  0000 C CNN
F 2 "DRILL_NP" H 10950 6100 60  0001 C CNN
F 3 "" H 10950 6100 60  0001 C CNN
	1    10950 6100
	1    0    0    -1  
$EndComp
$Comp
L DRILL U7
U 1 1 50066905
P 10950 6350
F 0 "U7" H 11000 6400 60  0001 C CNN
F 1 "DRILL" H 10950 6350 60  0000 C CNN
F 2 "DRILL_NP" H 10950 6350 60  0001 C CNN
F 3 "" H 10950 6350 60  0001 C CNN
	1    10950 6350
	1    0    0    -1  
$EndComp
$Comp
L CONN_8 P2
U 1 1 50065B8F
P 11000 2200
F 0 "P2" V 10950 2200 60  0000 C CNN
F 1 "Digital Output" V 11050 2200 60  0000 C CNN
F 2 "OQ_8P" H 11000 2200 60  0001 C CNN
F 3 "" H 11000 2200 60  0001 C CNN
	1    11000 2200
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 50065789
P 1850 1550
F 0 "C1" H 1900 1650 50  0000 L CNN
F 1 "10uF" H 1900 1450 50  0000 L CNN
F 2 "C0805" H 1850 1550 60  0001 C CNN
F 3 "" H 1850 1550 60  0001 C CNN
	1    1850 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 50065776
P 2250 1850
F 0 "#PWR012" H 2250 1850 30  0001 C CNN
F 1 "GND" H 2250 1780 30  0001 C CNN
F 2 "" H 2250 1850 60  0001 C CNN
F 3 "" H 2250 1850 60  0001 C CNN
	1    2250 1850
	1    0    0    -1  
$EndComp
$Comp
L 3V3 #PWR013
U 1 1 5004F8A3
P 4900 1300
F 0 "#PWR013" H 4900 1400 40  0001 C CNN
F 1 "3V3" H 4900 1425 40  0000 C CNN
F 2 "" H 4900 1300 60  0001 C CNN
F 3 "" H 4900 1300 60  0001 C CNN
	1    4900 1300
	1    0    0    -1  
$EndComp
$Comp
L 3V3 #PWR014
U 1 1 5004F895
P 2250 1250
F 0 "#PWR014" H 2250 1350 40  0001 C CNN
F 1 "3V3" H 2250 1375 40  0000 C CNN
F 2 "" H 2250 1250 60  0001 C CNN
F 3 "" H 2250 1250 60  0001 C CNN
	1    2250 1250
	1    0    0    -1  
$EndComp
Text GLabel 4400 4400 0    47   Output ~ 0
OUTPUT4
Text GLabel 4400 4300 0    47   Output ~ 0
OUTPUT3
Text GLabel 4400 4200 0    47   Output ~ 0
OUTPUT2
Text GLabel 4400 4100 0    47   Output ~ 0
OUTPUT1
Text GLabel 3600 2550 0    47   Input ~ 0
OUTPUT4
Text GLabel 3600 2450 0    47   Input ~ 0
OUTPUT3
Text GLabel 3600 2350 0    47   Input ~ 0
OUTPUT2
Text GLabel 3600 2250 0    47   Input ~ 0
OUTPUT1
$Comp
L LTV-847 U2
U 1 1 5004F732
P 5550 2450
F 0 "U2" H 5250 3350 60  0000 C CNN
F 1 "LTV846S" H 5550 1550 60  0000 C CNN
F 2 "OPTO-SMD16" H 5550 2450 60  0001 C CNN
F 3 "" H 5550 2450 60  0001 C CNN
	1    5550 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1850 4900 1850
Wire Wire Line
	4900 1300 4900 2750
Wire Wire Line
	4900 2150 5250 2150
Connection ~ 4900 1850
Wire Wire Line
	4900 2450 5250 2450
Connection ~ 4900 2150
Wire Wire Line
	4900 2750 5250 2750
Connection ~ 4900 2450
Wire Wire Line
	4150 2250 4650 2250
Wire Wire Line
	4650 2250 4650 2050
Wire Wire Line
	4650 2050 5250 2050
Wire Wire Line
	4150 2350 5250 2350
Wire Wire Line
	4150 2450 4650 2450
Wire Wire Line
	4650 2450 4650 2650
Wire Wire Line
	4650 2650 5250 2650
Wire Wire Line
	4150 2550 4550 2550
Wire Wire Line
	4550 2550 4550 2950
Wire Wire Line
	4550 2950 5250 2950
Wire Wire Line
	5850 2950 6350 2950
Wire Wire Line
	6350 2050 6350 4150
Wire Wire Line
	5850 2650 6350 2650
Connection ~ 6350 2950
Wire Wire Line
	5850 2350 6350 2350
Connection ~ 6350 2650
Wire Wire Line
	5850 2050 6350 2050
Connection ~ 6350 2350
Wire Wire Line
	6450 1850 5850 1850
Wire Wire Line
	6550 2050 7400 2050
Wire Wire Line
	6550 2150 5850 2150
Connection ~ 6550 2050
Wire Wire Line
	5850 2750 6450 2750
Wire Wire Line
	10650 2450 10600 2450
Connection ~ 10600 2450
$Comp
L CON-SENSOR2 P1
U 1 1 5004F5E5
P 1150 2000
F 0 "P1" H 1300 2400 60  0000 C CNN
F 1 "CON-SENSOR2" V 1300 2000 60  0000 C CNN
F 2 "CON-SENSOR2" H 1150 2000 60  0001 C CNN
F 3 "" H 1150 2000 60  0001 C CNN
	1    1150 2000
	-1   0    0    -1  
$EndComp
$Comp
L XMC1XXX24 U1
U 1 1 5A5F6B7E
P 6300 7050
F 0 "U1" H 6150 7450 60  0000 C CNN
F 1 "XMC1XXX24" H 6300 6650 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 6450 7800 60  0001 C CNN
F 3 "" H 6450 7800 60  0000 C CNN
	1    6300 7050
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX24 U1
U 2 1 5A5F6C8B
P 4950 5600
F 0 "U1" H 4800 6150 60  0000 C CNN
F 1 "XMC1XXX24" H 4950 5050 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5100 6350 60  0001 C CNN
F 3 "" H 5100 6350 60  0000 C CNN
	2    4950 5600
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX24 U1
U 3 1 5A5F6CEE
P 4950 4250
F 0 "U1" H 4800 4500 60  0000 C CNN
F 1 "XMC1XXX24" H 4950 4000 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5100 5000 60  0001 C CNN
F 3 "" H 5100 5000 60  0000 C CNN
	3    4950 4250
	1    0    0    -1  
$EndComp
$Comp
L XMC1XXX24 U1
U 4 1 5A5F6D59
P 4950 7050
F 0 "U1" H 4800 7500 60  0000 C CNN
F 1 "XMC1XXX24" H 4950 6600 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 5100 7800 60  0001 C CNN
F 3 "" H 5100 7800 60  0000 C CNN
	4    4950 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 4100 4600 4100
Wire Wire Line
	4600 4200 4400 4200
Wire Wire Line
	4400 4300 4600 4300
Wire Wire Line
	4600 4400 4400 4400
$Comp
L C C5
U 1 1 5A5F95FD
P 2250 1550
F 0 "C5" H 2300 1650 50  0000 L CNN
F 1 "1uF" H 2300 1450 50  0000 L CNN
F 2 "C0603F" H 2250 1550 60  0001 C CNN
F 3 "" H 2250 1550 60  0001 C CNN
	1    2250 1550
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 5A5F966A
P 5750 7000
F 0 "C6" H 5800 7100 50  0000 L CNN
F 1 "100nF" H 5800 6900 50  0000 L CNN
F 2 "C0603F" H 5750 7000 60  0001 C CNN
F 3 "" H 5750 7000 60  0001 C CNN
	1    5750 7000
	1    0    0    -1  
$EndComp
NoConn ~ 1500 1700
Wire Wire Line
	1500 1800 2250 1800
Wire Wire Line
	2250 1750 2250 1850
Connection ~ 2250 1800
Wire Wire Line
	1850 1750 1850 1800
Connection ~ 1850 1800
Wire Wire Line
	1500 1900 1650 1900
Wire Wire Line
	1650 1900 1650 1300
Wire Wire Line
	1650 1300 2250 1300
Wire Wire Line
	2250 1250 2250 1350
Connection ~ 2250 1300
Wire Wire Line
	1850 1350 1850 1300
Connection ~ 1850 1300
$Comp
L R_PACK4 RP5
U 1 1 5A5FA4C9
P 2000 2350
F 0 "RP5" H 2000 2800 50  0000 C CNN
F 1 "82" H 2000 2300 50  0000 C CNN
F 2 "4X0402" H 2000 2350 50  0001 C CNN
F 3 "" H 2000 2350 50  0000 C CNN
	1    2000 2350
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5A5FA5E0
P 1650 2550
F 0 "C4" H 1700 2650 50  0000 L CNN
F 1 "220pF" H 1700 2450 50  0000 L CNN
F 2 "C0402E" H 1650 2550 60  0001 C CNN
F 3 "" H 1650 2550 60  0001 C CNN
	1    1650 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR015
U 1 1 5A5FA8B0
P 1650 2800
F 0 "#PWR015" H 1650 2800 30  0001 C CNN
F 1 "GND" H 1650 2730 30  0001 C CNN
F 2 "" H 1650 2800 60  0001 C CNN
F 3 "" H 1650 2800 60  0001 C CNN
	1    1650 2800
	1    0    0    -1  
$EndComp
Text GLabel 2500 2000 2    47   Output ~ 0
S-CS
Text GLabel 2500 2100 2    47   Output ~ 0
S-CLK
Text GLabel 2500 2200 2    47   Output ~ 0
S-MOSI
Text GLabel 2500 2300 2    47   Input ~ 0
S-MISO
Wire Wire Line
	1500 2000 1800 2000
Wire Wire Line
	1500 2100 1800 2100
Wire Wire Line
	1500 2200 1800 2200
Wire Wire Line
	1800 2300 1500 2300
Wire Wire Line
	1650 2350 1650 2300
Connection ~ 1650 2300
Wire Wire Line
	1150 2450 1150 2800
Wire Wire Line
	1650 2800 1650 2750
Wire Wire Line
	2200 2000 2500 2000
Wire Wire Line
	2500 2100 2200 2100
Wire Wire Line
	2200 2200 2500 2200
Wire Wire Line
	2500 2300 2200 2300
$Comp
L GND #PWR016
U 1 1 5A5FCD06
P 5750 7400
F 0 "#PWR016" H 5750 7400 30  0001 C CNN
F 1 "GND" H 5750 7330 30  0001 C CNN
F 2 "" H 5750 7400 60  0001 C CNN
F 3 "" H 5750 7400 60  0001 C CNN
	1    5750 7400
	1    0    0    -1  
$EndComp
$Comp
L 3V3 #PWR017
U 1 1 5A5FCDE1
P 5750 6700
F 0 "#PWR017" H 5750 6800 40  0001 C CNN
F 1 "3V3" H 5750 6825 40  0000 C CNN
F 2 "" H 5750 6700 60  0001 C CNN
F 3 "" H 5750 6700 60  0001 C CNN
	1    5750 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 6750 5750 6750
Wire Wire Line
	5750 6700 5750 6800
Connection ~ 5750 6750
Wire Wire Line
	5750 7200 5750 7400
Wire Wire Line
	5950 7250 5750 7250
Connection ~ 5750 7250
Wire Wire Line
	5950 7350 5750 7350
Connection ~ 5750 7350
Text GLabel 4300 5850 0    47   Input ~ 0
S-CS
Text GLabel 4300 5950 0    47   Input ~ 0
S-CLK
Text GLabel 4300 6050 0    47   Input ~ 0
S-MOSI
Text GLabel 4300 6700 0    47   Output ~ 0
S-MISO
Wire Wire Line
	4300 5850 4600 5850
Wire Wire Line
	4600 5950 4300 5950
Wire Wire Line
	4300 6050 4600 6050
Wire Wire Line
	4300 6700 4600 6700
$Comp
L CONN_01X01 P3
U 1 1 5A607C86
P 4100 5250
F 0 "P3" H 4200 5250 50  0000 C CNN
F 1 "DEBUG" H 4100 5350 50  0000 C CNN
F 2 "kicad-libraries:DEBUG_PAD" H 4100 5250 50  0001 C CNN
F 3 "" H 4100 5250 50  0000 C CNN
	1    4100 5250
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P4
U 1 1 5A60946E
P 4100 5100
F 0 "P4" H 4200 5100 50  0000 C CNN
F 1 "BOOT" H 4100 4950 50  0000 C CNN
F 2 "SolderJumper" H 4100 5100 50  0001 C CNN
F 3 "" H 4100 5100 50  0000 C CNN
	1    4100 5100
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR018
U 1 1 5A60ABF9
P 4400 5200
F 0 "#PWR018" H 4400 5200 30  0001 C CNN
F 1 "GND" H 4400 5130 30  0001 C CNN
F 2 "" H 4400 5200 60  0001 C CNN
F 3 "" H 4400 5200 60  0001 C CNN
	1    4400 5200
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A60AFAE
P 4250 5450
F 0 "R2" V 4330 5450 50  0000 C CNN
F 1 "1k" V 4250 5450 50  0000 C CNN
F 2 "R0603F" H 4250 5450 60  0001 C CNN
F 3 "" H 4250 5450 60  0000 C CNN
	1    4250 5450
	0    1    1    0   
$EndComp
$Comp
L LED D2
U 1 1 5A60B078
P 3650 5450
F 0 "D2" H 3650 5550 50  0000 C CNN
F 1 "blue" H 3650 5350 50  0000 C CNN
F 2 "D0603F" H 3650 5450 50  0001 C CNN
F 3 "" H 3650 5450 50  0000 C CNN
	1    3650 5450
	1    0    0    -1  
$EndComp
$Comp
L 3V3 #PWR019
U 1 1 5A60B5AF
P 3350 5350
F 0 "#PWR019" H 3350 5450 40  0001 C CNN
F 1 "3V3" H 3350 5475 40  0000 C CNN
F 2 "" H 3350 5350 60  0001 C CNN
F 3 "" H 3350 5350 60  0001 C CNN
	1    3350 5350
	1    0    0    -1  
$EndComp
NoConn ~ 4600 7200
NoConn ~ 4600 7100
NoConn ~ 4600 7400
NoConn ~ 4600 6900
NoConn ~ 4600 6800
NoConn ~ 4600 5750
NoConn ~ 4600 5650
NoConn ~ 4600 5550
NoConn ~ 4600 5350
NoConn ~ 4600 7300
Wire Wire Line
	4600 5450 4500 5450
Wire Wire Line
	4000 5450 3850 5450
Wire Wire Line
	3450 5450 3350 5450
Wire Wire Line
	3350 5450 3350 5350
Wire Wire Line
	4300 5250 4600 5250
NoConn ~ 4600 7000
Wire Wire Line
	4300 5150 4400 5150
Wire Wire Line
	4400 5150 4400 5200
Wire Wire Line
	4600 5150 4500 5150
Wire Wire Line
	4500 5150 4500 5050
Wire Wire Line
	4500 5050 4300 5050
$EndSCHEMATC
