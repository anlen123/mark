#!/usr/bin/bash 

read -p "输入你的成绩: " score

case "$score" in
[9][0-9])
    echo "A"
    ;;
100)
    echo "A"
    ;;
[8][0-9])
    echo "B"
    ;;
[7][0-9])
    echo "C"
    ;;
[6][0-9])
    echo "D"
    ;;
*)
    echo "E"
    ;;
esac
