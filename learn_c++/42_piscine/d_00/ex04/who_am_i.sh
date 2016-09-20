#!/bin/sh
ldapsearch -LLL "cn=Sean Qian" dn 2>&-|awk 'NR==1{print $2}'
#We need to close the standard error output because the first 4 lines comes from that. Then we should use the awk to trim the search result. "NR==1" represent the first line and the "$2" means the second sector seperated by blank. 
