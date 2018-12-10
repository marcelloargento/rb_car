#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

#We want to be able to sleep but don't need all of time & space, just import sleep
from time import sleep
from sys import exit
#We alos need to use RPi.GPIO but we want to use it as GPIO
import pigpio as pigpio
import os,sys
def cbf(gpio, level, tick):
	if level==0:
		b=os.popen('aplay -q /var/www/cgi-bin/coinwin.wav','r',1)
		#sleep(4)

   
pi1 = pigpio.pi()   
cb1 = pi1.callback(27, pigpio.FALLING_EDGE, cbf)
sleep(20)
exit(0)

