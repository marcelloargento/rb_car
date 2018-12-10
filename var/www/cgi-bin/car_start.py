#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

import os # Import the os library

os.system("omxplayer -o local /var/www/cgi-bin/car_start.mp3")

print 'ok'
exit(0)
