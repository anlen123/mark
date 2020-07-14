package com.pool_C3P0.connection;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import com.mchange.v2.c3p0.DataSources;
import org.junit.Test;

import java.sql.Connection;
import java.sql.SQLException;

public class C3P0Test {

    //方式一:
    @Test
    public void testGetConnection() throws Exception {
        ComboPooledDataSource cpds = new ComboPooledDataSource();
        cpds.setDriverClass( "com.mysql.cj.jdbc.Driver" ); //loads the jdbc driver
        cpds.setJdbcUrl("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true");
        cpds.setUser("root");
        cpds.setPassword("123456");
        //设置相关参数,对数据库进行管理
        //设置初始化数据池中的连接数
        cpds.setInitialPoolSize(10);
        Connection conn = cpds.getConnection();
        System.out.println(conn);
        //销毁连接池
        DataSources.destroy(cpds);
    }

    //方式二 用配置文件
    @Test
    public void testGetConnection2() throws SQLException {
        ComboPooledDataSource cpds = new ComboPooledDataSource("helloc3p0");
        Connection conn = cpds.getConnection();
//        System.out.println(conn);
    }

}
