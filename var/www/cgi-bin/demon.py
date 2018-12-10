#!/usr/bin/python

from time import sleep
from sys import exit
import pigpio as pigpio

import RPi.GPIO as GPIO
import time,os,sys
GPIO.setmode(GPIO.BCM)

TRIG = 24 
ECHO = 25

#print "Distance Measurement In Progress"
GPIO.setup(TRIG,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)
GPIO.output(TRIG, False)
print "Waiting For Sensor To Settle"
time.sleep(2)
print "Started"
def dist():

	GPIO.output(TRIG, True)
	time.sleep(0.00001)
	GPIO.output(TRIG, False)
	while GPIO.input(ECHO)==0:
  		pulse_start = time.time()
	while GPIO.input(ECHO)==1:
  		pulse_end = time.time()
	pulse_duration = pulse_end - pulse_start
	distance = pulse_duration * 17150
	distance = round(distance, 2)
	return distance


def cbf(gpio, level, tick):
	if level==0:
		b=os.popen('aplay -q /var/www/cgi-bin/coinwin.wav','r',1)

   
pi1 = pigpio.pi()   
cb1 = pi1.callback(27, pigpio.FALLING_EDGE, cbf)
while True:
	d=dist()
	if d<4:
		pi1.write(18, 0) 
		pi1.write(23, 0)
		pi1.write(17, 0) 
		pi1.write(22, 0)
		b=os.popen('aplay -q /var/www/cgi-bin/frenata.wav','r',1)
		print "Distance:",d,"cm"
		pi1.write(17, 1) # set local Pi's gpio 4 low
		pi1.write(22, 1) # set tom's gpio 4 to high
		sleep(0.2)
		pi1.write(17, 0) # set local Pi's gpio 4 low
		pi1.write(22, 0) # set tom's gpio 4 to high
	time.sleep(0.05)



GPIO.cleanup()

exit(0)