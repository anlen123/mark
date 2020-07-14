#!/usr/bin/bash

function jx(){
	sum=1
	for((i=1;i<=$1;i++))
	do
		sum=$[$sum*$i]
	done
	echo $sum
	return $num
}

ans=`jx $1`
echo $ans