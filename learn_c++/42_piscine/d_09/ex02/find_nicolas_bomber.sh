#!/bin/sh
grep -i '^Nicolas[[:space:]]Bomber' $1|awk '{print $(NF-1)}'
