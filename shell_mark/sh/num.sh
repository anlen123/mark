#!/usr/bin/bash 
read -p "请输入一个数字: " num

while true
do
    if [[ ! "$num" =~ ^[0-9]+$ ]];then 
        read -p "重新输入数字: " num 
    else
        echo "YES"
        break
    fi
done
