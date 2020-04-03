# [Java获取随机数](https://www.cnblogs.com/haw2106/p/8036523.html)

```bash
方法1
(数据类型)(最小值+Math.random()*(最大值-最小值+1))
例:
(int)(1+Math.random()*(10-1+1))
从1到10的int型随数
方法2
获得随机数
for (int i=0;i<30;i++)
{System.out.println((int)(1+Math.random()*10));}
(int)(1+Math.random()*10)
通过java.Math包的random方法得到1-10的int随机数
公式是:最小值---最大值（整数）的随机数
（类型）最小值+Math.random()*最大值
方法3
Random ra =new Random();
for (int i=0;i<30;i++)
{System.out.println(ra.nextInt(10)+1);}
通过java.util包中的Random类的nextInt方法来得到1-10的int随机数
 
生成0到1之间的任意随机小数：
生成[0,d)区间的随机小数，d为任意正的小数，则只需要将nextDouble方法的返回值乘以d即可。

[n1，n2]

也就是 ra.nextDouble() * (n2-n1)+n1
```

