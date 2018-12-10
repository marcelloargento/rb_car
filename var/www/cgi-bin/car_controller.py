#!/usr/bin/python

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeNumber(value):
    
    bus.write_byte(address, 257)
    # bus.write_byte_data(address, 0, value)
    return -1

def writeArray(value,arr):
	bus.write_i2c_block_data(address,value,arr)
	return -1

def readNumber():
    number = bus.read_byte(address)
    # number = bus.read_byte_data(address, 1)
    return number
    
def avanti(spd):
	aa=writeArray(5,[spd])
	time.sleep(0.1)
	return -1
def indietro(spd):
	aa=writeArray(6,[spd])
	time.sleep(0.1)
	return -1
def stop():
	aa=writeArray(4,[0])
	time.sleep(0.1)
	return -1
def giraDx(spd):
	aa=writeArray(8,[spd])
	time.sleep(0.1)
	return -1
def giraSx(spd):
	aa=writeArray(7,[spd])
	time.sleep(0.1)
	return -1  
def stepAvanti(spd,dly):
	aa=writeArray(9,[spd,dly])
	time.sleep(0.1)
	return -1
def stepIndietro(spd,dly):
	aa=writeArray(10,[spd,dly])
	time.sleep(0.1)
	return -1
def stepDx(spd,dly):
	aa=writeArray(12,[spd,dly])
	time.sleep(0.1)
	return -1
def stepSx(spd,dly):
	aa=writeArray(11,[spd,dly])
	time.sleep(0.1)
	return -1  

while True:
    aa=0
    var = input("Enter 1 - 9: ")
    if not var:
        continue

    print var
	
    if var == 1:
	avanti(255)
    elif var == 2:
	stop()
    elif var == 3:
	indietro(255)
    elif var == 4:
	giraDx(255)
    elif var == 5:
	giraSx(255)
    elif var == 6:
	stepAvanti(255,5)
    elif var == 7:
	stepIndietro(255,5)
    elif var == 8:
	stepDx(255,5)
    elif var == 9:
	stepSx(255,5)
	

	

    
    print "RPI: Hi Arduino, I sent you ", aa
    # sleep one second
    time.sleep(1)

    number = readNumber()
    print "Arduino: Hey RPI, I received a digit ", number
    print