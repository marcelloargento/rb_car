#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

#We want to be able to sleep but don't need all of time & space, just import sleep
from time import sleep
from sys import exit
#We alos need to use RPi.GPIO but we want to use it as GPIO
import pigpio as pigpio

pi1 = pigpio.pi()       # pi1 accesses the local Pi's gpios
pi1.set_mode(27, pigpio.INPUT)
a=pi1.read(27)
print a
exit(0)
