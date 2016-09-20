#!/bin/sh
find . -type d -or -type f -name "*"|awk -F "/" '{print $NF}'|wc -l|sed 's/ //g'  
#In regex, . mean single char. So we need the use backslash
