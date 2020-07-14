#!/usr/bin/bash 

read -p "请输入number:" num 
read -p "请输入前缀: " prefix

for i in `seq $num`
do 
    {
    user=${prefix}_${i}
    id $user &>/dev/null
    if [ $? -eq 0 ];then 
        userdel -r $user
        if [ $? -eq 0 ];then 
            echo "$user userdel success!!"
        else
            echo "$user userdel false"
        fi
    else 
        echo "$user no exist"
    fi
    }&
done 

wait

echo "OK"
