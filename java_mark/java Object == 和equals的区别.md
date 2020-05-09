 # java Object == 和equals的区别

```c++
/*
 * ==:
 *      == 比较基本数据类型之间的相等-->>比较的是两个数据类型的保存的数据是否相同
 *      比较两个对象是否相等-->>比较两个对象的地址值是否相同
 *
 * //equals(Object ojb):
 *      只适用于引用数据类型
 *      equals是一个方法不是一个运算符
 *      Object类中的equals()定义:
 *      public boolean equals(Object obj){
 *          return(this==obj)
 *      }
 *      说明:Object类中定义的equals()和==作用相同,比较两个对象地址值值是否相等,即是否指向同一个地址
 *      But:
 *      像String , Date,File,包装类里面的都重写了Object里面的equals,比较的不是地址值,比较的是实体内容,而不是地址值
 *
 * 自定义的类如何使用equals(比较实体内容)
 *      比较每一个属性是否相等
 *
 *
 */
```

