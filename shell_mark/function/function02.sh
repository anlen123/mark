#!/usr/bin/bash

if [ $# -ne 3 ];then
	echo "error usage:`basename $0` part1 part2 part3"
	exit
fi

function fun(){
	echo $[$1 + $2 + $3]
}



echo `fun $1 $2 $3`