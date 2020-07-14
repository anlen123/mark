package com.TestExer;

import com.util.JDBCUtils;
import org.junit.Test;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.util.Scanner;

public class exer1 {

    @Test
    public void testInsert(){
        System.out.println("23333");
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入用户名");
        String name = scanner.next();
//        String name = "刘华强";
        System.out.print("请输入邮箱");
        String email = scanner.next();
//        String email = "1761512493@qq.com";
        System.out.print("请输入生日");
        String birthday = scanner.next();
//        String birthday = "1998-06-09";
        String sql = "insert into customers(name,email,birth) values(?,?,?)";
        int update = update(sql, name, email, birthday);
        if(update>0){
            System.out.println("成功");
        }else {
            System.out.println("失败");
        }
    }


    public int update(String sql,Object ...args){//sql中占位符的个数与可变形参的长度相同！
        Connection conn = null;
        PreparedStatement ps = null;
        try {
            //1.获取数据库的连接
            conn = JDBCUtils.getConnection();
            //2.预编译sql语句，返回PreparedStatement的实例
            ps = conn.prepareStatement(sql);
            //3.填充占位符
            for(int i = 0;i < args.length;i++){
                ps.setObject(i + 1, args[i]);//小心参数声明错误！！
            }
            //4.执行
//            ps.execute();

            return ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }finally{
            //5.资源的关闭
            JDBCUtils.closeResource(conn, ps);
        }
        return 0;
    }
}
