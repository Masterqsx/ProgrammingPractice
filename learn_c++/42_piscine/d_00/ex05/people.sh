#!/bin/sh
ldapsearch -LLL -S -cn "uid=z*" cn 2>&-|awk 'NR%3==2{
	for(i=2;i<=NF;i++){ # the NF is not size
		printf "%s ",$i
	}
	printf "\n"
}'
