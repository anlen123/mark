#!/usr/bin/bash

declare -A sex	
while read line
do
	# echo $line
	typee=`echo $line | awk '{print $2}'`
	# echo $typee
	let sex[$typee]++
	
done <sex.txt

for x in ${!sex[@]}
do
	echo $x: ${sex[$x]}
done 