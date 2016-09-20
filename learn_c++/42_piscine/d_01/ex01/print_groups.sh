#!/bin/sh
groups $FT_USER | sed "s/ /,/g"|tr -d "\n" #groups command just display group members
