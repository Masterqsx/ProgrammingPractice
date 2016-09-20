#!/bin/sh
re=$(ifconfig|grep "inet "|awk '{print $2}')
if test -z "$re"
then
	echo "Je suis perdu!\n"
else
	echo "$re"
fi
