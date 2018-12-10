#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

import smbus
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

def writeArray(value,arr):
	bus.write_i2c_block_data(address,value,arr)
	return -1
aa=writeArray(10,[255,30])
time.sleep(1)
print 'ok'
exit(0)