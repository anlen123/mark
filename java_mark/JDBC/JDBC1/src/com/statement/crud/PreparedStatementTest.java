package com.statement.crud;

import com.util.JDBCUtils;
import org.junit.Test;

import java.lang.reflect.Field;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.Scanner;

public class PreparedStatementTest {
    @Test
    public void testLogin() {
//        Scanner scanner=  new Scanner(System.in);
        System.out.println("请输入用户名:");
//        String user = scanner.nextLine();
        String user = "AA";
        System.out.println("请输入密码: ");
//        String password = scanner.nextLine();
        String password = "123456";
//        String sql = "SELECT user,password FROM user_table WHERE user="+user+" and password="+password+";";
        String sql = "SELECT user,password FROM user_table WHERE user= ? and password= ? ";
        User returnUser = getInstance(User.class,sql,user,password);
        if (returnUser != null) {
            System.out.println("登录成功");
        }else{
            System.out.println("用户名不存在或密码错误");
        }
    }
    /**
     * 解决sql注入问题
    */
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

}
