#!/usr/bin/bash
ping -c1 www.baidu.com&>/dev/null && echo "true" || echo "flase"

