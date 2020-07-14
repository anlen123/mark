package com.dao2;

import com.bean.Customer;
import com.util.JDBCUtils;

import java.lang.reflect.Field;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

/**
 * 封装了数据表的通用操作
 *
 */
public abstract class  BaseDAO<T>{
    private Class<T> clazz = null;


    {
        //获取当前DAO的子类的继承的泛型
        Type genericSuperclass = this.getClass().getGenericSuperclass();
        ParameterizedType parameterizedType = (ParameterizedType) genericSuperclass;
        Type[] actualTypeArguments = parameterizedType.getActualTypeArguments();
        clazz = (Class<T>) actualTypeArguments[0];
    }


    //2.0版本警告 事务
    public int update(Connection conn, String sql, Object... args) {//sql中占位符的个数与可变形参的长度相同！
        PreparedStatement ps = null;
        try {
//            1.获取数据库的连接
//            conn = JDBCUtils.getConnection();
            //1.预编译sql语句，返回PreparedStatement的实例
            ps = conn.prepareStatement(sql);
            //2.填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);//小心参数声明错误！！
            }
            //3.执行
//            ps.execute();

            return ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //4.资源的关闭
            JDBCUtils.closeResource(null, ps);
        }
        return 0;
    }

    /*
 通用查询,2.0版本 ,用与返回数据表中的多条记录 考虑上了事务
  */
    public List<T> getForList(Connection conn, String sql, Object... args) {
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

    /*
    返回一条查询数据
     */
    public  T getInstance(Connection conn, String sql, Object... args) {
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
//                list.add(t);
                return t;
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(null, ps, rs);
        }
        return null;
    }

    /*
    查询特殊值的方法
     */
    public <E> E getValue(Connection conn,String sql ,Object ...args){
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = conn.prepareStatement(sql);
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i+1,args[i]);
            }

            rs = ps.executeQuery();
            if(rs.next()){
                return (E) rs.getObject(1);
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            JDBCUtils.closeResource(null,ps,rs);
        }
        return null ;
    }
}
