package com.transaction;

import com.bean.User;
import com.util.JDBCUtils;
import org.junit.Test;

import java.lang.reflect.Field;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * 1.什么叫做事务.
 * 事务:一组逻辑单元,使数据从一种状态转换为另外一直状态
 *      一组逻辑操作单元,一个或者多组
 *
 */
public class TransactionTest {



    @Test
    public void testUpdate(){
        Connection conn = null;
        try {
            conn = JDBCUtils.getConnection();

            //取消数据的自动提交功能
            conn.setAutoCommit(false);

            String sql = "UPDATE user_table set balance = balance - 100 WHERE user = ?";
            update(conn, sql,"BB");

            //模拟网络异常
//        System.out.println(1/0);
            String sql1 = "UPDATE user_table set balance = balance + 100 WHERE user = ?";
            update(conn,sql1,"AA");
            System.out.println("success!!");

            //提交数据
            conn.commit();
        } catch (Exception e) {
            e.printStackTrace();
            //回滚数据
            try {
                if (conn != null) {
                    conn.rollback();
                }
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }finally {
            JDBCUtils.closeResource(conn,null);
        }

    }


    //2.0版本警告
    public int update(Connection conn,String sql,Object ...args){//sql中占位符的个数与可变形参的长度相同！
        PreparedStatement ps = null;
        try {
//            1.获取数据库的连接
//            conn = JDBCUtils.getConnection();
            //1.预编译sql语句，返回PreparedStatement的实例
            ps = conn.prepareStatement(sql);
            //2.填充占位符
            for(int i = 0;i < args.length;i++){
                ps.setObject(i + 1, args[i]);//小心参数声明错误！！
            }
            //3.执行
//            ps.execute();

            return ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }finally{
            //最后修改为最后自动提交数据,主要是.针对数据库连接池时的使用
            try {
                conn.setAutoCommit(true);
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }

            //4.资源的关闭
            JDBCUtils.closeResource(null, ps);
        }
        return 0;
    }

    /*
    通用查询,2.0版本 ,用与返回数据表中的一条记录 考虑上了事务
     */
    public static <T> List<T> query(Connection conn,Class<T> clazz, String sql, Object... args) {
//        Connection conn = null;
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
            JDBCUtils.closeResource(null, ps, rs);
        }
        return null;
    }

    @Test
    public void testSelect() throws Exception {
        Connection conn= JDBCUtils.getConnection();
        conn.setAutoCommit(false);
        //获取当前连接的隔离级别
        System.out.println(conn.getTransactionIsolation());
        String sql = "select user,password,balance from user_table where user = ? ";
        List<User> cc = query(conn, User.class, sql,"CC");
        JDBCUtils.closeResource(conn,null);
        System.out.println(cc);
    }

    @Test
    public void testUpdate2() throws Exception {
        Connection conn = JDBCUtils.getConnection();
        conn.setAutoCommit(false);
        String sql = "update user_table set balance = ? where user = ? ";
        int cc = update(conn, sql, 5000, "CC");

        conn.commit();
        JDBCUtils.closeResource(conn,null);
        Thread.sleep(15000);
        System.out.println(cc);
        System.out.println("修改结束");

    }

}
