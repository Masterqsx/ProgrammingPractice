#!/bin/sh
touch -A -000001 bomb.txt|stat -f%c bomb.txt
