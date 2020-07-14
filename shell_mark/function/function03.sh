#!/usr/bin/bash

arr=(1 2 3 4 5)

fun(){
	for x in "$@"
	do
		sum=$[$sum+$x]
	done
	
	echo $sum
}

echo `fun ${arr[@]}`