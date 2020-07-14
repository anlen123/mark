#!/usr/bin/bash 
if [ $# -eq 0 ]; then
    echo "`basename $0` no file!"
    exit
fi

if [ ! -f $1 ]; then 
    echo "not file!!"
    exit
fi 

for ip in `cat $1`
do 
    ping -c1 $ip &>/dev/null 
    if [ $? -eq 0 ];then
        echo -e " $ip true"
    else
        echo -e " $ip false"
    fi
done 
