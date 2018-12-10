#!/usr/bin/python

import os, sys, pygame 
from pygame import locals
import time
import smbus

# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address = 0x04

# set the delay between steps
stepDelay = 0.02



os.environ["SDL_VIDEODRIVER"] = "dummy"
pygame.init()

pygame.joystick.init() # main joystick device system

deadZone = 0.6 # make a wide deadzone
m1 = 0 # motor 1 (1 = forward / 2 = backwards)
m2 = 0 # motor 2 (1 = forward / 2 = backwards)
try:
   j = pygame.joystick.Joystick(0) # create a joystick instance
   j.init() # init instance
   print 'Enabled joystick: ' + j.get_name()
except pygame.error:
   print 'no joystick found.'

lastCmd="";
lastX=0;

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


def writeArray(value,arr):
	try:
		bus.write_i2c_block_data(address,value,arr)
	except IOError:
		print "except IOError"
	return -1         


while 1:
   for e in pygame.event.get(): # iterate over event stack
      if e.type == pygame.locals.JOYAXISMOTION: # Read Analog Joystick Axis
         x1 , y1 = j.get_axis(0), j.get_axis(1) # Left Stick
         x2 , y2 = j.get_axis(2), j.get_axis(3) # Right Stick

         print x1
         print y1
         print x2
         print y2
         print deadZone
	 print (round(90 * x2)+90)

         if x1 < -1 * deadZone:
             print 'Left Joystick 1'
             m1=3

         if x1 > deadZone:
             print 'Right Joystick 1'
             m1=4

         if (y1 <= deadZone and y1 >= -1 * deadZone) and (x1 <= deadZone and x1 >= -1 * deadZone):
    	     m1 = 0 # Dont go forward or backwards

         if y1 < -1 * deadZone:
             print 'Up Joystick 1'
             m1 = 1 # go forward
             print m1
             
         if y1 > deadZone:
             print 'Down Joystick 1'
             m1 = 2 # go forward
             print m1

         if y2 <= deadZone and y2 >= -1 * deadZone:
             m2 = 0 # Dont go forward or backwards
              
         if y2 < -1 * deadZone:
             print 'Up Joystick 2'
             m2 = 1

         if y2 > deadZone:
             print 'Down Joystick 2'
             m2 = 2

         if x2 < -1 * deadZone:
            print 'Left Joystick 2'

         if x2 > deadZone:
            print 'Right Joystick 2'
         print m1

	 if m1==1 and lastCmd<>"avanti":
	    stop()
	    avanti(255)
            lastCmd="avanti"
	 if m1==0 and lastCmd<>"stop":
	    stop()
	    lastCmd="stop"
	 if m1==2 and lastCmd<>"indietro":
            stop()
            indietro(255)
            lastCmd="indietro"
	 if m1==3 and lastCmd<>"giraSx":
            stop()
            giraSx(255)
            lastCmd="giraSx"
	 if m1==4 and lastCmd<>"giraDx":
            stop()
            giraDx(255)
            lastCmd="giraDx"

	 if lastX<> (round(90 * x2)+90):
		lastX=(round(90 * x2)+90)
		writeArray(13,[int(lastX)])
		