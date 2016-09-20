#!/bin/sh
rm -f testDay00;
mkfile 40 testDay00;#for set the initial size of the file
chmod u=r,g=rx,o=rx testDay00;#for set the permission 
touch -t 06012342 testDay00;#for change the timestamp
