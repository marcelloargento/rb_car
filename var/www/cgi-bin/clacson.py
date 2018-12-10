#!/usr/bin/python

print "Content-type:text/plain\r\n\r\n"
print ''

import os # Import the os library

os.system("aplay -q /var/www/cgi-bin/clacson.wav")
print 'ok'
exit(0)
