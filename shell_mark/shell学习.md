# shell学习

## 基础

```shell
切换su 

不加- 如 su lhq  nologshell

加- 如  su - lhq loginshell



read ip 是输入

位置变量

$1 是后面跟的第一个变量

设置环境变量的关键字 export (作用范围是全局)
```

# 预变量

| 参数处理 | 说明                                                         |
| :------- | :----------------------------------------------------------- |
| $#       | 传递到脚本的参数个数                                         |
| $*       | 以一个单字符串显示所有向脚本传递的参数。 如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。 |
| $$       | 脚本运行的当前进程ID号                                       |
| $!       | 后台运行的最后一个进程的ID号                                 |
| $@       | 与$*相同，但是使用时加引号，并在引号中返回每个参数。 如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。 |
| $-       | 显示Shell使用的当前选项，与[set命令](https://www.runoob.com/linux/linux-comm-set.html)功能相同。 |
| $?       | 显示最后命令的退出状态。0表示没有错误，其他任何值表明有错误。 |

```shell
ping 一个txt 里面的ip
#!/usr/bin/bash 
if [ $# -eq 0 ]; then
    echo "`basename $0` no file!"
    exit
fi

if [ ! -f $1 ]; then 
    echo "not file!!"
    exit
fi 

for ip in `cat $1`
do 
    ping -c1 $ip &>/dev/null 
    if [ $? -eq 0 ];then
        echo -e " $ip true"
    else
        echo -e " $ip false"
    fi
done
```

# 运算

```shell
1.expr 1 + 1
2.echo $((1+1))
3.echo $[1+1]
```

# 调试

```shell
bash -vx xx.sh

sh -n xx.sh  仅调试syntax error
sh -vx xx.sh 以调试的方式执行,并且,查询整个执行过程
```

# 切片

```shell
{14:11}~/sh ? url=www.baidu.com.cn
{14:12}~/sh ? echo ${#url} //长度
16
{14:12}~/sh ? echo ${url#www} //从前往后
.baidu.com.cn
{14:12}~/sh ? echo ${url#www*} 
.baidu.com.cn
{14:13}~/sh ? echo ${url#*.} 非贪婪
baidu.com.cn
{14:13}~/sh ? echo ${url##*.} 贪婪
cn
{14:13}~/sh ? echo ${url%com}  %从后往前
www.baidu.com.cn
{14:13}~/sh ? echo ${url%.com}
www.baidu.com.cn
{14:13}~/sh ? echo ${url%cn}
www.baidu.com.
{14:14}~/sh ? echo ${url%.cn}
www.baidu.com
{14:14}~/sh ? echo ${url%.*}
www.baidu.com
{14:14}~/sh ? echo ${url%%.*}
www
{14:14}~/sh ? 
```

```shell
字符串切片
{14:17}~/sh ? url=www.baidu.com.cn
{14:17}~/sh ? echo ${url:2:5}
w.bai
{14:18}~/sh ? echo ${url:5:5}
aidu.
{14:18}~/sh ? echo ${url:5}
aidu.com.cn
{14:18}~/sh ? 
```

```shell
替换

{14:19}~/sh ? url=www.baidu.com.cn
{14:20}~/sh ? echo ${url/baidu/google}
www.google.com.cn
{14:20}~/sh ? echo ${url/c/C}
www.baidu.Com.cn
{14:20}~/sh ? echo ${url//c/C}
www.baidu.Com.Cn
{14:20}~/sh ? 
```

```shell
{14:22}~/sh ? var1    
zsh: command not found: var1
{14:23}~/sh ? var2=
{14:23}~/sh ? var3=233
{14:23}~/sh ? echo ${var1-123}
123
{14:23}~/sh ? echo ${var2-123}

{14:23}~/sh ? echo ${var3-123}
233
```

```shell
shell 中的${}，##, %% , ：- ，：+， ？ 的使用
假设我们定义了一个变量为：
file=/dir1/dir2/dir3/my.file.txt

可以用${ }分别替换得到不同的值：
${file#*/}：删掉第一个/ 及其左边的字符串：dir1/dir2/dir3/my.file.txt
${file##*/}：删掉最后一个/  及其左边的字符串：my.file.txt
${file#*.}：删掉第一个.  及其左边的字符串：file.txt
${file##*.}：删掉最后一个.  及其左边的字符串：txt
${file%/*}：删掉最后一个 /  及其右边的字符串：/dir1/dir2/dir3
${file%%/*}：删掉第一个/  及其右边的字符串：(空值)
${file%.*}：删掉最后一个 .  及其右边的字符串：/dir1/dir2/dir3/my.file
${file%%.*}：删掉第一个 .   及其右边的字符串：/dir1/dir2/dir3/my

记忆的方法为：
# 是 去掉左边（键盘上#在 $ 的左边）
%是去掉右边（键盘上% 在$ 的右边）
单一符号是最小匹配；两个符号是最大匹配
${file:0:5}：提取最左边的5 个字节：/dir1
${file:5:5}：提取第5 个字节右边的连续5个字节：/dir2

也可以对变量值里的字符串作替换：
${file/dir/path}：将第一个dir 替换为path：/path1/dir2/dir3/my.file.txt
${file//dir/path}：将全部dir 替换为path：/path1/path2/path3/my.file.txt

利用${ } 还可针对不同的变数状态赋值(沒设定、空值、非空值)： 
${file-my.file.txt} ：假如$file 沒有设定，則使用my.file.txt 作传回值。(空值及非空值時不作处理) 
${file:-my.file.txt} ：假如$file 沒有設定或為空值，則使用my.file.txt 作傳回值。(非空值時不作处理)
${file+my.file.txt} ：假如$file 設為空值或非空值，均使用my.file.txt 作傳回值。(沒設定時不作处理)
${file:+my.file.txt} ：若$file 為非空值，則使用my.file.txt 作傳回值。(沒設定及空值時不作处理)
${file=my.file.txt} ：若$file 沒設定，則使用my.file.txt 作傳回值，同時將$file 賦值為my.file.txt 。(空值及非空值時不作处理)
${file:=my.file.txt} ：若$file 沒設定或為空值，則使用my.file.txt 作傳回值，同時將$file 賦值為my.file.txt 。(非空值時不作处理)
${file?my.file.txt} ：若$file 沒設定，則將my.file.txt 輸出至STDERR。(空值及非空值時不作处理)


${file:?my.file.txt} ：若$file 没设定或为空值，则将my.file.txt 输出至STDERR。(非空值時不作处理)

${#var} 可计算出变量值的长度：


${#file} 可得到27 ，因为/dir1/dir2/dir3/my.file.txt 是27个字节

我们只需要努力，然后剩下的交给时间。
分类: shell

```

# shell [    ] 中的参数

```shell
if [ str1 = str2 ]　　　　　  当两个串有相同内容、长度时为真 
if [ str1 != str2 ]　　　　　 当串str1和str2不等时为真 
if [ -n str1 ]　　　　　　    当串的长度大于0时为真(串非空) 
if [ -z str1 ]　　　　　　　 当串的长度为0时为真(空串) 
if [ str1 ]　　　　　　　　 当串str1为非空时为真
       -eq: 测试两个整数是否相等；比如 $A -eq $B
       -ne: 测试两个整数是否不等；不等，为真；相等，为假；
       -gt: 测试一个数是否大于另一个数；大于，为真；否则，为假；
       -lt: 测试一个数是否小于另一个数；小于，为真；否则，为假；
       -ge: 大于或等于
       -le：小于或等于 
if [-d $1]
     这个的意思是 从外面传一个参数给$1 -d是判断$!这个目录存不存在
     所以你要穿的参数如果是正确的文件目录名,则此时的判断值为0 即真
[ -f 判断参数 ] 判断一个普通文件是不是存在
[ -s 文件名 ] 文件存在且内容非空 即必须要一个空格以上的字符
[ -e 文件目录 ] 文件目录下是否不为空
[-z 字符串] 在if里的意思是 空 ,字符串长度为0，返回真


用man test可以查看文档
```

# 小总结

```shell
() 子shell
(()) 数值比较,运算,c语言
$() 命令替换  $(cmd)
$(()) 整数运算

{} 集合
${} 
[] 比较 用于if 
[[]]  正则比较 [[ =~ ]] 
$[] 运算
```

# shell并发

```shell
打开一个文件
exec 6<> /file
{11:43}~ ➭ ll /proc/$$/fd
total 0
lrwx------ 1 root root 64 Jul 10 11:07 0 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 1 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 10 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 2 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 6 -> /root/file1
{11:44}~ ➭ echo "123" >> /proc/$$/fd/6
{11:44}~ ➭ cat file1
123
{11:44}~ ➭ 
{11:44}~ ➭ rm -rf file1
{11:44}~ ➭ ll /proc/$$/fd           
total 0
lrwx------ 1 root root 64 Jul 10 11:07 0 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 1 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 10 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 2 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 6 -> /root/file1 (deleted)
{11:44}~ ➭ cp /proc/$$/fd/6 ~

关闭文件
{11:46}~ ➭ exec 6<&-
{11:46}~ ➭ ll /proc/$$/fd
total 0
lrwx------ 1 root root 64 Jul 10 11:07 0 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 1 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 10 -> /dev/pts/0
lrwx------ 1 root root 64 Jul 10 11:07 2 -> /dev/pts/0
```

# 数组

```shell
#!/usr/bin/bash

a=(1 2 3 4 5)
echo ${a[2]} 
echo ${a[@]} #查看全部数组元素
echo ${!a[@]} #查看全部数组的下标


declare -A b #定义关联数组(字典) 的定义
b=([age]=22 [name]=华强)

echo ${b[age]}
echo ${b[@]}
echo ${!b[@]}

```

# expect

```shell
#!/usr/bin/expect

set ip [lindex $argv 0]
set user [lindex $argv 1]
set password LHQlhq1761512493
set timeout 5


spawn ssh $user@$ip

expect {
	"yes/no" { send "yes\r"; exp_continue }
	"password:" { send "$password\r" };
}

interact

```

# scp

```shell
#!/usr/bin/bash
file=$1
#ip=$2
pass=LHQlhq1761512493

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

```

# 函数定义

```shell
#!/usr/bin/bash

function jx(){
	sum=1
	for((i=1;i<=$1;i++))
	do
		sum=$[$sum*$i]
	done
	echo $sum
	return $num
}

ans=`jx $1`
echo $ans
```

# 管道多线程并发

```shell
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

```

# 正则

## 普通字符

普通字符包括没有显式指定为元字符的所有可打印和不可打印字符。这包括所有大写和小写字母、所有数字、所有标点符号和一些其他符号。

------

## 非打印字符

非打印字符也可以是正则表达式的组成部分。下表列出了表示非打印字符的转义序列：

| 字符 | 描述                                                         |
| :--- | :----------------------------------------------------------- |
| \cx  | 匹配由x指明的控制字符。例如， \cM 匹配一个 Control-M 或回车符。x 的值必须为 A-Z 或 a-z 之一。否则，将 c 视为一个原义的 'c' 字符。 |
| \f   | 匹配一个换页符。等价于 \x0c 和 \cL。                         |
| \n   | 匹配一个换行符。等价于 \x0a 和 \cJ。                         |
| \r   | 匹配一个回车符。等价于 \x0d 和 \cM。                         |
| \s   | 匹配任何空白字符，包括空格、制表符、换页符等等。等价于 [ \f\n\r\t\v]。注意 Unicode 正则表达式会匹配全角空格符。 |
| \S   | 匹配任何非空白字符。等价于 [^ \f\n\r\t\v]。                  |
| \t   | 匹配一个制表符。等价于 \x09 和 \cI。                         |
| \v   | 匹配一个垂直制表符。等价于 \x0b 和 \cK。                     |

------

## 特殊字符

所谓特殊字符，就是一些有特殊含义的字符，如上面说的 **runoo\*b** 中的 *****，简单的说就是表示任何字符串的意思。如果要查找字符串中的 ***** 符号，则需要对 ***** 进行转义，即在其前加一个 **\**: **runo\*ob** 匹配 runo*ob。

许多元字符要求在试图匹配它们时特别对待。若要匹配这些特殊字符，必须首先使字符"转义"，即，将反斜杠字符**\** 放在它们前面。下表列出了正则表达式中的特殊字符：

| 特别字符 | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| $        | 匹配输入字符串的结尾位置。如果设置了 RegExp 对象的 Multiline 属性，则 $ 也匹配 '\n' 或 '\r'。要匹配 $ 字符本身，请使用 \$。 |
| ( )      | 标记一个子表达式的开始和结束位置。子表达式可以获取供以后使用。要匹配这些字符，请使用 \( 和 \)。 |
| *        | 匹配前面的子表达式零次或多次。要匹配 * 字符，请使用 \*。     |
| +        | 匹配前面的子表达式一次或多次。要匹配 + 字符，请使用 \+。     |
| .        | 匹配除换行符 \n 之外的任何单字符。要匹配 . ，请使用 \. 。    |
| [        | 标记一个中括号表达式的开始。要匹配 [，请使用 \[。            |
| ?        | 匹配前面的子表达式零次或一次，或指明一个非贪婪限定符。要匹配 ? 字符，请使用 \?。 |
| \        | 将下一个字符标记为或特殊字符、或原义字符、或向后引用、或八进制转义符。例如， 'n' 匹配字符 'n'。'\n' 匹配换行符。序列 '\\' 匹配 "\"，而 '\(' 则匹配 "("。 |
| ^        | 匹配输入字符串的开始位置，除非在方括号表达式中使用，当该符号在方括号表达式中使用时，表示不接受该方括号表达式中的字符集合。要匹配 ^ 字符本身，请使用 \^。 |
| {        | 标记限定符表达式的开始。要匹配 {，请使用 \{。                |
| \|       | 指明两项之间的一个选择。要匹配 \|，请使用 \|。               |

------

## 限定符

限定符用来指定正则表达式的一个给定组件必须要出现多少次才能满足匹配。有 ***** 或 **+** 或 **?** 或 **{n}** 或 **{n,}** 或 **{n,m}** 共6种。

正则表达式的限定符有：

| 字符  | 描述                                                         |
| :---- | :----------------------------------------------------------- |
| *     | 匹配前面的子表达式零次或多次。例如，zo* 能匹配 "z" 以及 "zoo"。* 等价于{0,}。 |
| +     | 匹配前面的子表达式一次或多次。例如，'zo+' 能匹配 "zo" 以及 "zoo"，但不能匹配 "z"。+ 等价于 {1,}。 |
| ?     | 匹配前面的子表达式零次或一次。例如，"do(es)?" 可以匹配 "do" 、 "does" 中的 "does" 、 "doxy" 中的 "do" 。? 等价于 {0,1}。 |
| {n}   | n 是一个非负整数。匹配确定的 n 次。例如，'o{2}' 不能匹配 "Bob" 中的 'o'，但是能匹配 "food" 中的两个 o。 |
| {n,}  | n 是一个非负整数。至少匹配n 次。例如，'o{2,}' 不能匹配 "Bob" 中的 'o'，但能匹配 "foooood" 中的所有 o。'o{1,}' 等价于 'o+'。'o{0,}' 则等价于 'o*'。 |
| {n,m} | m 和 n 均为非负整数，其中n <= m。最少匹配 n 次且最多匹配 m 次。例如，"o{1,3}" 将匹配 "fooooood" 中的前三个 o。'o{0,1}' 等价于 'o?'。请注意在逗号和两个数之间不能有空格。 |

以下正则表达式匹配一个正整数，**[1-9]**设置第一个数字不是 0，**[0-9]\*** 表示任意多个数字：

# egrep

## grep和egrep正则表达式

Published on 2017-06-04 15:50 in 分类: [Linux](https://www.cnblogs.com/python-gm/category/1013254.html) with [evescn](https://cnblogs.com/python-gm)

https://www.cnblogs.com/python-gm/p/6940756.html

分类: [Linux](https://www.cnblogs.com/python-gm/category/1013254.html)



 Linux上文本处理三剑客

- grep ：文本过滤( 模式：pattern) 工具
- grep, egrep, fgrep （不支持正则表达式搜索，但搜索纯文本的数据最快）
- sed ：stream editor ，文本编辑工具
- awk ：Linux上实际是gawk(GUN awk) ，文本报告生成器  

 正则表达式：

- 由一类特殊字符及文本字符所编写的模式，其中有些字符（元字符）不表示字符字面意义，而表示控制或通配的功能
- 支持正则表达式的程序：grep, vim, less,nginx等 

 

 正则表达式分两类：

- 基本正则表达式：BRE 

```bash
grep` `,``egrep` `-G 　　
```

- 扩展正则表达式：ERE 

```bash
grep` `-E, ``egrep
```

```
-E：使用ERE``　　　扩展的正则表达式　　
```

 练习:

1、显示/etc/passwd 文件中不以/bin/bash 结尾的行

```bash
grep -v "/bin/bash$" /etc/passwd
```

2 、显示用户rpc 默认的shell 程序

```bash
grep "^rpc\>" /etc/passwd | cut -d: -f7
```

3 、找出/etc/passwd 中的两位或三位数

```bash
grep -E "\<[0-9]{2,3}\>" /etc/passwd
```

4 、找出"netstat -tan" 命令的结果中以'LISTEN' 后跟0 、1或多个空白字符结尾的行

```bash
netstat -tan | grep "\<LISTEN[[:space:]]*$"
```

 

 egrep及扩展的正则表达式

egrep = grep -E
egrep [OPTIONS] PATTERN [FILE...]
　　选项：

　　　　-i,-o,-v,q,-A,-B,-C
　　　　-G:支持基本的正则表达式

 扩展正则表达式元字符：

 练习：

1 、显示当前系统上，root,gao和user1用户的相关信息

```bash
# grep -E "\<(root|gao|uer1)\>" /etc/passwd
```

2 、统计以root 身份登录的每个远程主机IP

```bash
# who | grep -E "^root\>" | wc -l
```

3 、使用egrep 取出/etc/rc.d/init.d/functions

```bash
# echo "/etc/rc.d/init.d/functions" | grep -oE "[^/]+/?$"
```

# Sed

sed 是一种在线的非交互的编译器，它一次处理一行的内容。处理时，把当前处理的行储存在临时缓冲区中，称为模式空间，接着用sed命令处理缓冲区的内容，处理完成后，把缓冲区的内容送往屏幕。接着处理下一行，这样不断重复，直到文件末尾。文件内容并没有改变，除非你使用重定向储存输出。
 sed主要用来自动编辑一个或多个文件；简化对文件的反复操作；编写转换程序等。

## 用法 sed + 命令  ＋目录/文件1  目录/文件2

## sed支持正则表达式

使用基本元字符集 ^, $, ., *, [], [^], < >,(),{}
 使用扩展元字符集 ?, +, { }, |, ( )使用扩展元字符的方式：
 sed -r

## 基本用法



```bash
sed -r ' '      mypasswd
sed -r ' p '   mypasswd
```

屏蔽默认输出使用 -n选项



```bash
sed -rn ' p '   mypasswd
sed -rn  ' /root/p '  mypasswd  显示root的行    ^匹配root开头   ^root
```

## 探索替换*（重要）

sed会自动打印文件的每一行， 查找模式匹配的行，找到后执行后面的命令，默认是输出（不加-n）



```bash
sed -r ' s/root/shark/ '  mypasswd
搜索每一行，找到有root的，只替换第一个
sed -r ' s/root/shark/g '  mypasswd
搜索每一行，找到有root的进行全局替换
sed -r ' s/root/shark/gi '   mypasswd
i  同时忽略大小写
sed -r '  /root/d ' mypasswd
找到含有root的进行删除
```

## 删除命令拓展



```bash
sed -r 'd'  mypasswd
全部分删除
sed -r  ' 3   d '
删除第三行
sed -r  ' 1,3 d ' 
第一行到第三行都删除
sed -r ' /root/ d '
含有root的字符串删除
sed -r ' /root/,5 d '
从含有root字符串的行开始，一直到第5行进行删除
sed -r ' /^adm/，20 d '
从行首是adm 的行开始，一直到20行进行删除
sed -r ' /^adm/ ,+2 d ' 
从行首是adm的行，以及此后两行的进行删除
sed -r ' /root/ !d '
含有root的行不删除，其他都删除
sed -r ' 1~2 d '
奇数行删除，其实就是匹配到行号除以2，余数是1的行
sed -rn ' 0~2  p '
偶数行打印
```

## sed参数大全

a 在当前行后添加一行或多行
 c 用新文本修改（替换）当前行中的文本
 d 删除行
 i 在当前行之前插入文本
 l 列出非打印字符
 p 打印行
 n 读入下一输入行，并从下一条命令而不是第一条命令开始对其的处理
 q 结束或退出sed
 ! 对所选行以外的所有行应用命令

s 用一个字符串替换另一个
 s 替换标志
 g 全局替换
 i 忽略大小写
 r 从文件中读
 w 将行写入文件
 y 将字符转换为另一字符（不支持正则表达式）

h  清除保持空间的内容后，把模式空间里的内容复制到保持空间
 H  把模式空间里的内容追加到保持空间
 g  清除模式空间的内容后， 取出保持空间的内容，并复制到模式空间
 G  取出保持空间的内容，追加在模式空间原有内容的后面
 x  交换模式空间与保持空间的内容

# Linux sed 命令

[![Linux 命令大全](https://www.runoob.com/images/up.gif) Linux 命令大全](https://www.runoob.com/linux/linux-command-manual.html)

Linux sed 命令是利用脚本来处理文本文件。

sed 可依照脚本的指令来处理、编辑文本文件。

Sed 主要用来自动编辑一个或多个文件、简化对文件的反复操作、编写转换程序等。

## 语法

```bash
sed [-hnV][-e<script>][-f<script文件>][文本文件]
```

## **参数说明**：

- -e<script>或--expression=<script> 以选项中指定的script来处理输入的文本文件。
- -f<script文件>或--file=<script文件> 以选项中指定的script文件来处理输入的文本文件。
- -h或--help 显示帮助。
- -n或--quiet或--silent 仅显示script处理后的结果。
- -V或--version 显示版本信息。

## **动作说明**：

- a ：新增， a 的后面可以接字串，而这些字串会在新的一行出现(目前的下一行)～
- c ：取代， c 的后面可以接字串，这些字串可以取代 n1,n2 之间的行！
- d ：删除，因为是删除啊，所以 d 后面通常不接任何咚咚；
- i ：插入， i 的后面可以接字串，而这些字串会在新的一行出现(目前的上一行)；
- p ：打印，亦即将某个选择的数据印出。通常 p 会与参数 sed -n 一起运行～
- s ：取代，可以直接进行取代的工作哩！通常这个 s 的动作可以搭配正规表示法！例如 1,20s/old/new/g 就是啦！

### 实例

在testfile文件的第四行后添加一行，并将结果输出到标准输出，在命令行提示符下输入如下命令：

```bash
sed -e 4a\newLine testfile 
```

首先查看testfile中的内容如下：

```bash
$ cat testfile #查看testfile 中的内容  
HELLO LINUX!  
Linux is a free unix-type opterating system.  
This is a linux testfile!  
Linux test 
```

使用sed命令后，输出结果如下：

```bash
$ sed -e 4a\newline testfile #使用sed 在第四行后添加新字符串  
HELLO LINUX! #testfile文件原有的内容  
Linux is a free unix-type opterating system.  
This is a linux testfile!  
Linux test  
newline 
```

### 以行为单位的新增/删除

将 /etc/passwd 的内容列出并且列印行号，同时，请将第 2~5 行删除！

```bash
[root@www ~]# nl /etc/passwd | sed '2,5d'
1 root:x:0:0:root:/root:/bin/bash
6 sync:x:5:0:sync:/sbin:/bin/sync
7 shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
.....(后面省略).....
```

sed 的动作为 '2,5d' ，那个 d 就是删除！因为 2-5 行给他删除了，所以显示的数据就没有 2-5 行罗～ 另外，注意一下，原本应该是要下达 sed -e 才对，没有 -e 也行啦！同时也要注意的是， sed 后面接的动作，请务必以 '' 两个单引号括住喔！

只要删除第 2 行

```bash
nl /etc/passwd | sed '2d' 
```

要删除第 3 到最后一行

```bash
nl /etc/passwd | sed '3,$d' 
```

在第二行后(亦即是加在第三行)加上『drink tea?』字样！

```bash
[root@www ~]# nl /etc/passwd | sed '2a drink tea'
1 root:x:0:0:root:/root:/bin/bash
2 bin:x:1:1:bin:/bin:/sbin/nologin
drink tea
3 daemon:x:2:2:daemon:/sbin:/sbin/nologin
.....(后面省略).....
```

那如果是要在第二行前

```bash
nl /etc/passwd | sed '2i drink tea' 
```

如果是要增加两行以上，在第二行后面加入两行字，例如 **Drink tea or .....** 与 **drink beer?**

```bash
[root@www ~]# nl /etc/passwd | sed '2a Drink tea or ......\
> drink beer ?'
1 root:x:0:0:root:/root:/bin/bash
2 bin:x:1:1:bin:/bin:/sbin/nologin
Drink tea or ......
drink beer ?
3 daemon:x:2:2:daemon:/sbin:/sbin/nologin
.....(后面省略).....
```

每一行之间都必须要以反斜杠『 \ 』来进行新行的添加喔！所以，上面的例子中，我们可以发现在第一行的最后面就有 \ 存在。

### 以行为单位的替换与显示

将第2-5行的内容取代成为『No 2-5 number』呢？

```bash
[root@www ~]# nl /etc/passwd | sed '2,5c No 2-5 number'
1 root:x:0:0:root:/root:/bin/bash
No 2-5 number
6 sync:x:5:0:sync:/sbin:/bin/sync
.....(后面省略).....
```

透过这个方法我们就能够将数据整行取代了！

仅列出 /etc/passwd 文件内的第 5-7 行

```bash
[root@www ~]# nl /etc/passwd | sed -n '5,7p'
5 lp:x:4:7:lp:/var/spool/lpd:/sbin/nologin
6 sync:x:5:0:sync:/sbin:/bin/sync
7 shutdown:x:6:0:shutdown:/sbin:/sbin/shutdown
```

可以透过这个 sed 的以行为单位的显示功能， 就能够将某一个文件内的某些行号选择出来显示。

### 数据的搜寻并显示

搜索 /etc/passwd有root关键字的行

```bash
nl /etc/passwd | sed '/root/p'
1  root:x:0:0:root:/root:/bin/bash
1  root:x:0:0:root:/root:/bin/bash
2  daemon:x:1:1:daemon:/usr/sbin:/bin/sh
3  bin:x:2:2:bin:/bin:/bin/sh
4  sys:x:3:3:sys:/dev:/bin/sh
5  sync:x:4:65534:sync:/bin:/bin/sync
....下面忽略 
```

如果root找到，除了输出所有行，还会输出匹配行。

使用-n的时候将只打印包含模板的行。

```bash
nl /etc/passwd | sed -n '/root/p'
1  root:x:0:0:root:/root:/bin/bash
```

### 数据的搜寻并删除

删除/etc/passwd所有包含root的行，其他行输出

```bash
nl /etc/passwd | sed  '/root/d'
2  daemon:x:1:1:daemon:/usr/sbin:/bin/sh
3  bin:x:2:2:bin:/bin:/bin/sh
....下面忽略
#第一行的匹配root已经删除了
```

### 数据的搜寻并执行命令

搜索/etc/passwd,找到root对应的行，执行后面花括号中的一组命令，每个命令之间用分号分隔，这里把bash替换为blueshell，再输出这行：

```bash
nl /etc/passwd | sed -n '/root/{s/bash/blueshell/;p;q}'    
1  root:x:0:0:root:/root:/bin/blueshell
```

最后的q是退出。

### 数据的搜寻并替换

除了整行的处理模式之外， sed 还可以用行为单位进行部分数据的搜寻并取代。基本上 sed 的搜寻与替代的与 vi 相当的类似！他有点像这样：

```bash
sed 's/要被取代的字串/新的字串/g'
```

先观察原始信息，利用 /sbin/ifconfig 查询 IP

```bash
[root@www ~]# /sbin/ifconfig eth0
eth0 Link encap:Ethernet HWaddr 00:90:CC:A6:34:84
inet addr:192.168.1.100 Bcast:192.168.1.255 Mask:255.255.255.0
inet6 addr: fe80::290:ccff:fea6:3484/64 Scope:Link
UP BROADCAST RUNNING MULTICAST MTU:1500 Metric:1
.....(以下省略).....
```

本机的ip是192.168.1.100。

将 IP 前面的部分予以删除

```bash
[root@www ~]# /sbin/ifconfig eth0 | grep 'inet addr' | sed 's/^.*addr://g'
192.168.1.100 Bcast:192.168.1.255 Mask:255.255.255.0
```

接下来则是删除后续的部分，亦即： 192.168.1.100 Bcast:192.168.1.255 Mask:255.255.255.0

将 IP 后面的部分予以删除

```bash
[root@www ~]# /sbin/ifconfig eth0 | grep 'inet addr' | sed 's/^.*addr://g' | sed 's/Bcast.*$//g'
192.168.1.100
```

### 多点编辑

一条sed命令，删除/etc/passwd第三行到末尾的数据，并把bash替换为blueshell

```bash
nl /etc/passwd | sed -e '3,$d' -e 's/bash/blueshell/'
1  root:x:0:0:root:/root:/bin/blueshell
2  daemon:x:1:1:daemon:/usr/sbin:/bin/sh
```

-e表示多点编辑，第一个编辑命令删除/etc/passwd第三行到末尾的数据，第二条命令搜索bash替换为blueshell。

### 直接修改文件内容(危险动作)

sed 可以直接修改文件的内容，不必使用管道命令或数据流重导向！ 不过，由於这个动作会直接修改到原始的文件，所以请你千万不要随便拿系统配置来测试！ 我们还是使用文件 regular_express.txt 文件来测试看看吧！

regular_express.txt 文件内容如下：

```bash
[root@www ~]# cat regular_express.txt 
runoob.
google.
taobao.
facebook.
zhihu-
weibo-
```

利用 sed 将 regular_express.txt 内每一行结尾若为 . 则换成 !

```bash
[root@www ~]# sed -i 's/\.$/\!/g' regular_express.txt
[root@www ~]# cat regular_express.txt 
runoob!
google!
taobao!
facebook!
zhihu-
weibo-
```

:q:q

利用 sed 直接在 regular_express.txt 最后一行加入 **# This is a test**:

```bash
[root@www ~]# sed -i '$a # This is a test' regular_express.txt
[root@www ~]# cat regular_express.txt 
runoob!
google!
taobao!
facebook!
zhihu-
weibo-
# This is a test
```

由於 $ 代表的是最后一行，而 a 的动作是新增，因此该文件最后新增 **# This is a test**！

sed 的 **-i** 选项可以直接修改文件内容，这功能非常有帮助！举例来说，如果你有一个 100 万行的文件，你要在第 100 行加某些文字，此时使用 vim 可能会疯掉！因为文件太大了！那怎办？就利用 sed 啊！透过 sed 直接修改/取代的功能，你甚至不需要使用 vim 去修订！

# AWK

## 选项参数说明：

```shell
-F fs or --field-separator fs
指定输入文件折分隔符，fs是一个字符串或者是一个正则表达式，如-F:。
-v var=value or --asign var=value
赋值一个用户定义变量。
-f scripfile or --file scriptfile
从脚本文件中读取awk命令。
-mf nnn and -mr nnn
对nnn值设置内在限制，-mf选项限制分配给nnn的最大块数目；-mr选项限制记录的最大数目。这两个功能是Bell实验室版awk的扩展功能，在标准awk中不适用。
-W compact or --compat, -W traditional or --traditional
在兼容模式下运行awk。所以gawk的行为和标准的awk完全一样，所有的awk扩展都被忽略。
-W copyleft or --copyleft, -W copyright or --copyright
打印简短的版权信息。
-W help or --help, -W usage or --usage
打印全部awk选项和每个选项的简短说明。
-W lint or --lint
打印不能向传统unix平台移植的结构的警告。
-W lint-old or --lint-old
打印关于不能向传统unix平台移植的结构的警告。
-W posix
打开兼容模式。但有以下限制，不识别：/x、函数关键字、func、换码序列以及当fs是一个空格时，将新行作为一个域分隔符；操作符**和**=不能代替^和^=；fflush无效。
-W re-interval or --re-inerval
允许间隔正则表达式的使用，参考(grep中的Posix字符类)，如括号表达式[[:alpha:]]。
-W source program-text or --source program-text
使用program-text作为源代码，可与-f命令混用。
-W version or --version
打印bug报告信息的版本
```

```shell
awk -F':' '{print $1}' /etc/passwd

awk  'BEGIN{FS=":";OFS="---"} {print $1,$2} END{print 123}' /etc/passwd

awk  'BEGIN{FS=":";OFS="---"} {print $1,$2}' /etc/passwd

df | grep '/' | awk '$4>1000000 {print $4}'

$0 文件本身
NR 所有文件显示行号
FNR 显示对于当前文件的行号
NF 保存记录字段数
FS 默认分隔符
OFS 把,映射为的值
RS 记录分隔符
ORS 输入的分隔符

awk -F[ \t:] 后面可以加正则的 -F后面

ps -ef | awk '$1~/^root/'  匹配第一列是root开头的行
用正则的时候,,,前后加/

```

## printf

```shell
awk  'BEGIN{FS=":"} {printf "%-15s %-15s %-15s\n", $1,$2,$3}' /etc/passwd
输出占位格式

```

## 条件表达式

```shell
df | grep "/"  | awk '{ if($4>=10000000){print $0} else {print "2333"}}'
2333
2333
2333
2333
/dev/vda1       41152812 5875668  33373436  15% /
overlay         41152812 5875668  33373436  15% /var/lib/docker/overlay2/bbf1e03279cfbbf5c0af2814c5c05ace215eb61b94cf25db0e6fb81a5cf2722c/merged
2333
2333
```

## 算数运算

```shell
df | grep "/"  | awk '{if($4>100000){print $4":"$4*9}}'
1929672:17367048
1939748:17457732
1939388:17454492
1940064:17460576
33373420:300360780
33373420:300360780
388016:3492144

```

## 逻辑运算

```shell
df | grep "/"| awk '$1~/^tmp/ && $4>=100000{print $4}' 
或者
df | grep "/"| awk '{if($1~/^tmp/ &&  $4>=100000){print $4}}'
1939744
1939388
1940064
388016
df | grep "/"| awk '$1~/^tmp/ || $4>=100000{print $4}' 
1929672
1939744
1939388
1940064
33373412
33373412
388016
df | grep "/"| awk '!($1~/^tmp/ &&  $4>=100000){print $4}' 
1929672
33373412
33373412
65536

```

## AWK 的 if else do while 

```shell
df | grep "/"| awk '{if($1~/^tmp/ &&  $4>=100000){print $4}}'

df | grep "/"| awk '{if($1~/^tmp/){++i}}END{print "开头是tmp的有:"i"个"}' 
开头是tmp的有:4个

awk '{i=1;while(i<=NF){print $i;i++}}' t.txt
111
222
333
444
555
666
777
888
awk '{for(i=1;i<=NF;i++){print $i}}' t.txt
111
222
333
444
555
666
777
888

```

## awk的数组

```shell
awk -F":"  '{username[x++]=$1} END{for(i =0;i<x;i++){print username[i]}}'  /etc/passwd
root
bin
daemon
adm
lp
sync
shutdown
halt
mail
operator
games
ftp
nobody
systemd-network
dbus
polkitd
sshd
postfix
chrony
nscd
tcpdump
tss
dockerroot
ntp
www
mysql
lhq
saslauth
mailnull
smmsp

awk -F":"  '{username[x++]=$1} END{for(i in username){print i,username[i]}}'  /etc/passwd
26 lhq
17 postfix
4 lp
27 saslauth
18 chrony
5 sync
28 mailnull
19 nscd
6 shutdown
29 smmsp
7 halt
8 mail
9 operator
10 games
20 tcpdump
11 ftp
21 tss
12 nobody
22 dockerroot
13 systemd-network
0 root
23 ntp
14 dbus
1 bin
24 www
15 polkitd
2 daemon
25 mysql
16 sshd
3 adm

awk -F":" '{shells[$NF]++} END{for(key in shells){print key, shells[key]}}' /etc/passwd 
/bin/bash 1
/bin/sync 1
/sbin/nologin 25
/sbin/halt 1
/bin/zsh 1
/sbin/shutdown 1


netstat -ant | grep ':80' | awk '{status[$NF]++} END{for(i in status){print i,status[i]}}' 
LISTEN 1
ESTABLISHED 1


ss -ant | grep ":80" | awk '{status[$1]++} END{for(i in status) {print i, status[i]}}' 
LISTEN 1
ESTAB 1

ss -an | grep ':80' | awk '{if(length($2)==6){cout++}}END{print cout}' 
4

```

## AWK 使用外部变量

```shell
方法一: 双引号,内部双引号用\转义
{14:18}~ ➭ var=bash ;echo "123 456" | awk "gsub(/123/,\"$var\")"
bash 456

方法二:  用双引号把单引号括起来
var=bash ;echo "123 shell" | awk 'gsub(/123/,"'"$var"'")'
bash shell
方法三:用-v 参数
echo "123 shell" | awk -v var="bash" 'gsub(/123/,var)'
bash shell
```

