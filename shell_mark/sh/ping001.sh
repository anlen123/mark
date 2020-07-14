#!/usr/bin/bash 
ip=liuhuaqiang.top
#for i in {1..5}
i=1
while [ $i -le 5 ]
do
    ping -c1 $ip &>/dev/null 
    if [ $? -eq 0 ];then 
        echo "$ip is true"
    else
        echo "$ip is false"
    fi
    #let i++
    let i++
done
