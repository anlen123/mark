# java对象的赋值直接赋值的"指针"

内存直接改变

```java
package com.test5;

public class Assignment {
    public static void main(String[] args) {
        int x = 10;
        int y = x;
        System.out.println("x = "+x+",y = "+y);
        y = 11;
        System.out.println("x = "+x+",y = "+y);

        order o1 = new order();
        o1.id = 10;
        order o2 = o1;
        System.out.println("o1.id = " + o1.id +", o2.id = "+o2.id);
        o2.id = 11;
        System.out.println("o1.id = " + o1.id +", o2.id = "+o2.id);

    }
}

class order{
    int id;
}
```

```bash
inout
x = 10,y = 10
x = 10,y = 11
o1.id = 10, o2.id = 10
o1.id = 11, o2.id = 11
```

