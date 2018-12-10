#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

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

i=0
while i<500:
	i=i+1	
	d=dist()
	if d<4:
		b=os.popen('aplay -q /var/www/cgi-bin/frenata.wav','r',1)
		print "Distance:",d,"cm"
	time.sleep(0.05)



GPIO.cleanup()

exit(0)