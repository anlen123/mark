#!/usr/bin/bash 
#read -p "请输入你ping的ip: " ip

#ip=www.baidu.com

ping -c1 $1 &>/dev/null 
if [ $? -eq 0 ];then
    echo "$1 true"
else 
    echo "$1 false"
fi
