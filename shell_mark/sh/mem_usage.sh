#!/usr/bin/bash 

mem_used=`free -m | grep "^Mem" | awk '{print $3}'`
mem_total=`free -m | grep "^Mem" | awk '{print $2}'`

war_file=~/sh/mem_errer

echo $mem_used
echo $mem_total
mem_percent=$[mem_used*100/mem_total]

echo "当前内存百分比 : $mem_percent"

if [ $mem_percent -ge 10 ];then 
    echo  "`date +%F-%H` memory:${mem_percent}%" > $war_file
fi

#if [ -f $war_file ];then 
    #mail -s "mem_war...." lhq < $war_file
#fi
