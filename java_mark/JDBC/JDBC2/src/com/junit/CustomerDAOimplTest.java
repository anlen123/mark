package com.junit;

import com.bean.Customer;
import com.dao.CustomerDAOimpl;
import com.pool_Druid.util.JDBCUtils;
import org.junit.Test;

import java.sql.Connection;
import java.sql.Date;
import java.util.List;

public class CustomerDAOimplTest {
    private CustomerDAOimpl dao = new CustomerDAOimpl();

    @Test
    public void insert() throws Exception {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            dao.insert(conn,cust);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void deleteById() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
//            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            dao.deleteById(conn,26);
            System.out.println("删除成功");
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void update() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
            Customer cust = new Customer(18, "贝多芬", "xiao@qq.com", new Date(15444454546L));
            dao.update(conn,cust);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void getCustomerById() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection3();
//            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            Customer customerById = dao.getCustomerById(conn, 18);
            System.out.println(customerById);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void getAll() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
//            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            List<Customer> all = dao.getAll(conn);
            all.forEach(System.out::println);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void getCount() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
//            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            Long count = dao.getCount(conn);
            System.out.println(count);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }

    @Test
    public void getMaxBirth() {
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();
//            Customer cust = new Customer(1, "刘华强", "xiao@qq.com", new Date(1545454546L));
            Date maxBirth = dao.getMaxBirth(conn);
            System.out.println(maxBirth);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JDBCUtils.closeResource(conn,null);
        }
    }
}