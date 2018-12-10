#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

#We want to be able to sleep but don't need all of time & space, just import sleep
from time import sleep
from sys import exit
#We alos need to use RPi.GPIO but we want to use it as GPIO
import RPi.GPIO as GPIO
GPIO.setwarnings(False) 
#Setup the Pi to use BCM mode
GPIO.setmode(GPIO.BCM)
#Output the pins 17,18,22,23

GPIO.setup(17,GPIO.OUT)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)

#All Pins setup!
#Now lets make the robot spin for 1 second left
print "Test 17"
GPIO.output(17,1)
sleep(3)
GPIO.output(17,0)

print "Test 18"
GPIO.output(18,1)
sleep(3)
GPIO.output(18,0)

print "Test 22"
GPIO.output(22,1)
sleep(3)
GPIO.output(22,0)

print "Test 23"
GPIO.output(23,1)
sleep(3)
GPIO.output(23,0)

print "end test"

#Now lets clean up the GPIO code
GPIO.cleanup()
print 'ok'
exit(0)
