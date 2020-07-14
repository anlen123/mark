package com.preparedstatement.curd;

import com.bean.Customer;
import com.bean.Order;
import com.util.JDBCUtils;
import org.junit.Test;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * 用Preparedstatement来替换Statement,实现数据表的增删查改
 * 查
 */

public class PreparedStatementQueryTest {


    @Test
    public void testGetForList(){
        String sql = "select id,name,email from customers where id < ? ";
        List<Customer> forList = getForList(Customer.class, sql, 12);
        forList.forEach(System.out::println);

        String sql1 = "select order_id as orderId,order_name as orderName from `order`";
        List<Order> forList1 = getForList(Order.class, sql1);
        forList1.forEach(System.out::println);
    }
    public <T> List<T> getForList(Class<T> clazz, String sql, Object... args) {
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据
            ResultSetMetaData rsmd = rs.getMetaData();
            //获取列数
            int columnCount = rsmd.getColumnCount();

            ArrayList<T> list = new ArrayList<>();
            while (rs.next()) {
                T t = clazz.newInstance();//反射创建实例类


                for (int i = 0; i < columnCount; i++) {
                    Object ColumnValue = rs.getObject(i + 1);
                    //cust指定的某个属性赋值
                    String columnLabel = rsmd.getColumnLabel(i + 1);

                    //反射,属性赋值
                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, ColumnValue);
                }
                list.add(t);
            }
            return list;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps, rs);
        }
        return null;
    }

    @Test
    public void testGetInstance() {
        String sql = "select id,name,email from customers where id = ? ";
        Customer instance = getInstance(Customer.class, sql, 12);
        System.out.println(instance);

        String sql1 = "select order_id as orderId,order_name as orderName from `order` where order_id= ? ";
        Order instance1 = getInstance(Order.class, sql1, 2);
        System.out.println(instance1);
    }

    //通用查询操作
    public <T> T getInstance(Class<T> clazz, String sql, Object... args) {
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据
            ResultSetMetaData rsmd = rs.getMetaData();
            //获取列数
            int columnCount = rsmd.getColumnCount();
            if (rs.next()) {
                T t = clazz.newInstance();//反射创建实例类
                for (int i = 0; i < columnCount; i++) {
                    Object ColumnValue = rs.getObject(i + 1);
                    //cust指定的某个属性赋值
                    String columnLabel = rsmd.getColumnLabel(i + 1);

                    //反射,属性赋值
                    Field field = clazz.getDeclaredField(columnLabel);
                    field.setAccessible(true);
                    field.set(t, ColumnValue);
                }
                return t;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps, rs);
        }
        return null;
    }


    @Test
    public void testQueryForCustomers() throws Exception {
        String sql = "select id,name,birth,email from customers where id= ?";
        Customer customer = queryForCustomers(sql, 1);
        System.out.println(customer);

        String sql1 = "select name,email from customers where name= ?";
        Customer customer1 = queryForCustomers(sql1, "周杰伦");
        System.out.println(customer1);

    }

    /**
     * 针对Customers 表的通用操作
     */
    public Customer queryForCustomers(String sql, Object... args) throws Exception {
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            conn = JDBCUtils.getConnection();
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);
            }
            rs = ps.executeQuery();
            //获取结果集的元数据
            ResultSetMetaData rsmd = rs.getMetaData();
            //获取列数
            int columnCount = rsmd.getColumnCount();
            if (rs.next()) {
                Customer cust = new Customer();
                for (int i = 0; i < columnCount; i++) {
                    Object ColumnValue = rs.getObject(i + 1);
                    //cust指定的某个属性赋值
                    String columnName = rsmd.getColumnName(i + 1);

                    //反射,属性赋值
                    Field field = Customer.class.getDeclaredField(columnName);
                    field.setAccessible(true);
                    field.set(cust, ColumnValue);
                }
                return cust;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps, rs);
        }
        return null;
    }

    @Test
    public void testQuery1() {
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet resultSet = null;
        try {
            conn = JDBCUtils.getConnection();
            String sql = "select id,name,email,birth from customers where id= ? ";
            ps = conn.prepareStatement(sql);
            ps.setObject(1, 1);

            //执行并返回结果集
            resultSet = ps.executeQuery();
            if (resultSet.next()) {
                int id = resultSet.getInt(1);
                String name = resultSet.getString(2);
                String email = resultSet.getString(3);
                Date birth = resultSet.getDate(4);
                //方式一:
                //            直接输出
//                System.out.println(id+name+email+birth);
                //方式二:
//                Object[] data = new Object[]{id,name,email,birth};
                //方式三: 将数据封装成一个对象
                Customer customer = new Customer(id, name, email, birth);
                System.out.println(customer);

            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps, resultSet);
        }
    }
}
