#!/bin/sh
cat /etc/passwd|grep "^[^#]*$"|awk -F ":" 'NR%2==0{print $1}'|rev|sort -r|sed -n "$FT_LINE1,$FT_LINE2 p"|xargs|sed 's/ /, /g'|sed 's/$/./'|tr -d "\n" 
