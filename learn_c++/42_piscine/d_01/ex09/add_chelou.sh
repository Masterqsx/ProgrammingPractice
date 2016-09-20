#!/bin/sh
echo "$FT_NBR1" + "$FT_NBR2"|tr "'\"\?\!\\" "02341"|tr "mrdoc" "0-4"|xargs echo "obase=13;ibase=5;"|bc|tr "0-9ABC" "gtaio luSnemf"
#remember the sequence of obase and ibase is critical
