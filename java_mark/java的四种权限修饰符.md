# java的四种权限修饰符

Java权限修饰符public、 protected、 private置于类的成员定义前，用来限
定对象对该类成员的访问权限。

| 修饰符    | 类内部 | 同一个包 | 不同包的子类 | 同一个工程 |
| --------- | ------ | -------- | ------------ | ---------- |
| private   | YES    |          |              |            |
| 缺省      | YES    | YES      |              |            |
| protected | YES    | YES      | YES          |            |
| public    | YES    | YES      | YES          | YES        |

对于class的权限修饰只可以用public和default(缺省)。
➢public类可以在任意地方被访问。
➢default类只可以被同-一个包内部的类访问。