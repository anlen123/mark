package com.TestExer;

import com.util.JDBCUtils;
import org.junit.Test;
import sun.security.jca.GetInstance;

import java.lang.reflect.Field;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class exer2 {
    //添加一条记录
    @Test
    public void testInsert() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("四级/六级:");
        int type = scanner.nextInt();
        System.out.print("身份证号:");
        String IDcard = scanner.next();
        System.out.print("准考证号:");
        String examCard = scanner.next();
        System.out.print("学生姓名:");
        String studentName = scanner.next();
        System.out.print("所在城市:");
        String location = scanner.next();
        System.out.print("考试成绩:");
        int grade = scanner.nextInt();

        String sql = "insert into examstudent(type,IDCard,examCard,studentName,location,grade) values(?,?,?,?,?,?)";
        int insertCount = update(sql, type, IDcard, examCard, studentName, location, grade);
        if (insertCount > 0) {
            System.out.println("添加成功");
        } else {
            System.out.println("添加失败");
        }
    }

    public int update(String sql, Object... args) {//sql中占位符的个数与可变形参的长度相同！
        Connection conn = null;
        PreparedStatement ps = null;
        try {
            //1.获取数据库的连接
            conn = JDBCUtils.getConnection();
            //2.预编译sql语句，返回PreparedStatement的实例
            ps = conn.prepareStatement(sql);
            //3.填充占位符
            for (int i = 0; i < args.length; i++) {
                ps.setObject(i + 1, args[i]);//小心参数声明错误！！
            }
            //4.执行
//            ps.execute();

            return ps.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //5.资源的关闭
            JDBCUtils.closeResource(conn, ps);
        }
        return 0;
    }


    //问题二:根据身份证号或者准考证号来查询学生信息
    @Test
    public void queryWithIDCardOrExamCard() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请选择你要输入的类型:");
        System.out.println("a.准考证号");
        System.out.println("b.身份证号");

        String selection = scanner.next();
        if ("a".equalsIgnoreCase(selection)) {
            System.out.print("请输入准考证号:");
            String examCard = scanner.next();
            String sql = "select FlowID as flowID,Type as type,IDCard,ExamCard as examCard,StudentName as name,Location as location ,Grade as grade from examstudent where examCard = ? ";
            List<Student> examstudent = query(Student.class, sql, examCard);

            System.out.println(examstudent);

        } else if ("b".equalsIgnoreCase(selection)) {
            System.out.print("请输入身份证号:");
        } else {
            System.out.println("你的输入有误!!");
        }
    }

    public <T> List<T> query(Class<T> clazz, String sql, Object... args) {
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
//        System.out.println(args.length);
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


    //删除信息
    @Test
    public void deleteByExamCard() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入学生的考号:");
        String examCard = scanner.next();
//        查询有无此人
//        String sql = "select FlowID as flowID,Type as type,IDCard,ExamCard as examCard,StudentName as name,Location as location ,Grade as grade from examstudent where examCard = ? ";
//        List<Student> query = query(Student.class, sql, examCard);
////        System.out.println(query.size());
//        if(query.size()==0){
//            System.out.println("没这个人!");
//        }
//        else{
//            String sql1 = "delete from examstudent where examCard = ? ";
//            int update = update(sql1, examCard);
//            if(update>0){
//                System.out.println("成功");
//            }
//            else{
//                System.out.println("失败");
//            }
//        }
        String sql1 = "delete from examstudent where examCard = ? ";
        int update = update(sql1, examCard);
        if(update>0){
            System.out.println("删除成功");
        }else{
            System.out.println("查无此人");
        }
    }
}
