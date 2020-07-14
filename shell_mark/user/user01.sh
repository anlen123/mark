#!/usr/bin/bash 

###############################
#creater:anlen123
#mail:1761512493@qq.com
#qq:1761512493 
##############################

read -p "请输入number:" num 

if [[ ! $num =~ ^[0-9]+$ || $num =~ ^0+$ ]];then 
    echo "error: no number"
    exit
fi


read -p "请输入前缀: " prefix

if [ -z ${prefix}  ];then
    echo "prefix length is zore"
    exit
fi

for i in `seq $num`
do 
    {
    user=${prefix}_${i}
    useradd $user
    if [ $? -eq 0 ];then 
        echo "qwertyui" |passwd $user &>/dev/null
        if [ $? -eq 0 ]; then 
            echo "$user create success!!"
        fi 
    fi
    }&
done 

wait
echo "falish"
