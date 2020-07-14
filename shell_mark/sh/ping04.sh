#!/usr/bin/bash 
read -p "请输入你ping的ip: " ip

#ip=www.baidu.com

ping -c1 $ip &>/dev/null 
if [ $? -eq 0 ];then
    echo "$ip true"
else 
    echo "$ip false"
fi
