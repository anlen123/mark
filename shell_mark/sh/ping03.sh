#!/usr/bin/bash 

ip=www.baidu.com

if ping -c1 $ip &>/dev/null;then
    echo "$ip true"
else 
    echo "$ip false"
fi
