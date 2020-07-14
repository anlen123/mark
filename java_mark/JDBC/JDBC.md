# JDBC

## jdk1.8 mysql8.0 连接数据库

### 方式一

```java
@Test
public void testConnection() throws SQLException {
    Driver driver=new com.mysql.cj.jdbc.Driver();

    String url = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true";
    Properties info=new Properties();
    info.setProperty("user","root");
    info.setProperty("password","123456");
    Connection conn = driver.connect(url,info);
}
```

### 方式二

```java
@Test
public void testConnection2() throws Exception {
    Class<?> aClass = Class.forName("com.mysql.cj.jdbc.Driver");
    Driver  driver = (Driver)aClass.newInstance();//反射,有更好的可一移植性
    
    String url = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true";
    Properties info=new Properties();
    info.setProperty("user","root");
    info.setProperty("password","123456");

    Connection conn = driver.connect(url,info);
}
```

### 方式三

```java
//方式三 用DriverManger替换Driver
@Test
public void testConnection3() throws SQLException, ClassNotFoundException, IllegalAccessException, InstantiationException {
    //获取Driver
    Class<?> aClass = Class.forName("com.mysql.cj.jdbc.Driver");
    Driver  driver = (Driver)aClass.newInstance();

    //提供三个连接基本信息
    String url = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true";
    String user = "root";
    String password = "123456";
    //注册驱动
    DriverManager.registerDriver(driver);

    //获取连接
    Connection conn = DriverManager.getConnection(url,user,password);
}
```

### 方式四

```java
//方式四
@Test
public void testConnection4() throws SQLException, ClassNotFoundException, IllegalAccessException, InstantiationException {
    //提供三个连接基本信息
    String url = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true";
    String user = "root";
    String password = "123456";
    //加载驱动  相较于方式三,省略注册驱动操作,在mysql的Driver的实现类中自己实现了注册方法
    Class.forName("com.mysql.cj.jdbc.Driver");

    //获取连接
    Connection conn = DriverManager.getConnection(url,user,password);
}
```

### 方式五

```java
//方式五,最终版  将四个信息到配置文件中,读取配置文件来读
@Test
public void testConnection5() throws Exception {
    //1.读取配置文件中的4个基本信息
    InputStream is = ConnectionTest.class.getClassLoader().getResourceAsStream("jdbc.properties");

    Properties properties = new Properties();
    properties.load(is);
    String user=properties.getProperty("user");
    String password=properties.getProperty("password");
    String url=properties.getProperty("url");
    String driverClass=properties.getProperty("driverClass");

    //2.加载驱动
    Class.forName(driverClass);

    //3.获取连接
    Connection conn = DriverManager.getConnection(url, user, password);

}
```

