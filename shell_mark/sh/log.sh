#!/usr/bin/bash 
printf "
+---------------------------+
|   1.阿里云轻量级服务器    |
|   2.送的半年的阿里云ESC   |
+---------------------------+
"
read -p "你要连接哪一个服务器:" num

case $num in 
1) 
	sshpass -p "LHQlhq1761512493" ssh root@123.56.145.243
	;;
2) 
	sshpass -p "LHQlhq1761512493" ssh root@47.94.82.228
	;;
*)
	echo "error!"
	;;
esac
