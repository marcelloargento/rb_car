#!/bin/bash
irsend SEND_ONCE Robosapienv1 BURP

echo "Content-type: text/html"
echo ""
sleep 2
echo -n 'Hello World'



exit 0
