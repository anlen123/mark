package com.dbutils;

import com.bean.Customer;
import com.pool_Druid.util.JDBCUtils;
import org.apache.commons.dbutils.QueryRunner;
import org.apache.commons.dbutils.ResultSetHandler;
import org.apache.commons.dbutils.handlers.*;
import org.junit.Test;

import java.sql.Connection;
import java.sql.Date;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;

/**
 * 工具类库,封装了数据库的增删改查操作
 */
public class QueryRunnerTest {
    @Test
    public void testInsert(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            String sql = "insert into customers(name,email,birth) values(?,?,?)";
            conn = JDBCUtils.getConnection3();

            int insertCount = runner.update(conn, sql, "华强", "1715155645@gmail.com", "2020-10-10");
            System.out.println(insertCount);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn, null);
        }
    }

    //测试查询
    @Test
    public void testQuery1(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select id ,name ,email,birth from customers where id = ? ";
            //用于封装表中的记录
            BeanHandler<Customer> handler = new BeanHandler<>(Customer.class);
            Customer query = runner.query(conn, sql, handler, 32);
            System.out.println(query);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    //测试查询多条记录
    @Test
    public void testQuery2(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select id ,name ,email,birth from customers where id < ? ";
            //用于封装表中的记录
//            BeanHandler<Customer> handler = new BeanHandler<>(Customer.class);
            BeanListHandler<Customer> handler = new BeanListHandler<>(Customer.class);
            List<Customer> query = runner.query(conn, sql, handler, 32);
//            System.out.println(query);
            query.forEach(System.out::println);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    //测试查询 mapHandler 数据中,以键值对的形式存在
    @Test
    public void testQuery3(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select id ,name ,email,birth from customers where id = ? ";
            //用于封装表中的记录
//            BeanHandler<Customer> handler = new BeanHandler<>(Customer.class);
            MapHandler mapHandler = new MapHandler();
            Map<String, Object> query = runner.query(conn, sql, mapHandler, 32);
            System.out.println(query);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    //测试查询多条记录
    @Test
    public void testQuery4(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select id ,name ,email,birth from customers where id < ? ";
            //用于封装表中的记录
//            BeanHandler<Customer> handler = new BeanHandler<>(Customer.class);
//            BeanListHandler<Customer> handler = new BeanListHandler<>(Customer.class);
            MapListHandler handler = new MapListHandler();
            List<Map<String, Object>> query = runner.query(conn, sql, handler, 32);
//            System.out.println(query);
            query.forEach(System.out::println);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    /*
    ScalarHandler scalarHandler = new ScalarHandler();用于查询特殊值
     */
    @Test
    public void testQuery5(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select count(*) from customers";
            ScalarHandler scalarHandler = new ScalarHandler();
            Long query = (Long) runner.query(conn, sql, scalarHandler);
            System.out.println(query);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }
    @Test
    public void testQuery6(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select max(birth) from customers";
            ScalarHandler scalarHandler = new ScalarHandler();
            Date query = (Date) runner.query(conn, sql, scalarHandler);
            System.out.println(query);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }


    //自定义resultSetHandler类
    @Test
    public void testQuery7(){
        Connection conn = null;
        try {
            QueryRunner runner = new QueryRunner();
            conn = JDBCUtils.getConnection3();
            String sql = "select id ,name ,email,birth from customers where id = ? ";
            //用于封装表中的记录
//            BeanHandler<Customer> handler = new BeanHandler<>(Customer.class);

            ResultSetHandler<Customer> handler = new ResultSetHandler<Customer>(){

                @Override
                public Customer handle(ResultSet resultSet) throws SQLException {

//                    return new Customer(12,"龙","chenglong@qq.com",new Date(5645646465L));
                    if (resultSet.next()){
                        int id = resultSet.getInt("id");
                        String name = resultSet.getString("name");
                        String email = resultSet.getString("email");
                        Date birth = resultSet.getDate("birth");
                        Customer customer = new Customer(id, name, email, birth);
                        return customer;
                    }
                    return null;
                }
            };

            Customer query = runner.query(conn, sql, handler, 32);
            System.out.println(query);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }
}
