#!/usr/bin/bash
file=$1
#ip=$2

cat <<-EOF
+---------------------------+
|   1.阿里云轻量级服务器    |
|   2.送的半年的阿里云ESC   |
+---------------------------+
EOF
echo -en "你要进入哪个服务器："
read num
if [ $num -eq 1 ];then
    ip=123.56.145.243
elif [ $num -eq 2 ];then
    ip=47.94.82.228
else
    echo "error!!"
    exit
fi

scp -r $1 ssh $ip:~

