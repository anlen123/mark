#!/bin/sh

PS3="你的选项是:"
select choice in disk_partition filesystem cpu_load mem_util quit
do
    case "$choice" in 
        disk_partition)
            fdisk -l
            ;;
        filesystem)
            df -h
            ;;
        cpu_load)
            uptime
            ;;
        mem_util)
            free -m 
            ;;
        quit)
            break
            ;;
        *)
            echo "输入错误"
        esac
done
