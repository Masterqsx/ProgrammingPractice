#!/bin/sh
ldapsearch -LLL "cn=*bon*" dn 2>&-|grep -v "^$"|wc -l|sed 's/ //g'
