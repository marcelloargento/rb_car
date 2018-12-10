#!/bin/bash


echo "Content-type: text/plain"
echo ""
# Save the old internal field separator.
  OIFS="$IFS"

# Set the field separator to & and parse the QUERY_STRING at the ampersand.
  IFS="${IFS}&"
  set $QUERY_STRING
  Args="$*"
  IFS="$OIFS"

# Next parse the individual "name=value" tokens.

  ARGX=""
  ARGY=""
  ARGZ=""

  for i in $Args ;do

#       Set the field separator to =
        IFS="${OIFS}="
        set $i
        IFS="${OIFS}"

        case $1 in
                # Don't allow "/" changed to " ". Prevent hacker problems.
                p1) ARGX="`echo $2 | sed 's|[\]||g' | sed 's|%20| |g'`"
                       ;;
                # Filter for "/" not applied here
                p2) ARGY="`echo $2 | sed 's|%20| |g'`"
                       ;;
                p3) ARGZ="${2/\// /}"
                       ;;
                *)     echo "<hr>Warning:"\
                            "<br>Unrecognized variable \'$1\' passed by FORM in QUERY_STRING.<hr>"
                       ;;

        esac
  done

sleep $ARGX
echo -n 'Hello World'



exit 0
