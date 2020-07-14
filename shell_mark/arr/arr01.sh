#!/usr/bin/bash

a=(1 2 3 4 5)
echo ${a[2]}
echo "全是元素:"${a[@]} \\n
echo "全部索引:"${!a[@]}
echo "切片:"${a[@]:2:2}

declare -A b
b=([age]=22 [name]=华强)

echo ${b[age]}
echo ${b[@]}
echo ${!b[@]}
