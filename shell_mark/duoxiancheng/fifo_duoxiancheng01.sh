#!/usr/bin/bash 

thread=5
fifo_name=/tmp/$$.fifo

# 创建一个命名管道
mkfifo $fifo_name

# 打开文件描述符
exec 8<> $fifo_name

# 删除管道文件(但是描述没有释放)
rm $fifo_name

for i in `seq $thread`
do 
	echo >&8
done



for i in `seq 100`
do
	read -u 8
	{
	echo "$i"
	echo >&8
	}&
	
done

wait

# 关闭文件描述符
exec 8>&-

echo "finish"
