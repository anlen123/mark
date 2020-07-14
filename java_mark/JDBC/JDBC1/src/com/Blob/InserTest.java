package com.Blob;

import com.util.JDBCUtils;
import org.junit.Test;

import java.sql.Connection;
import java.sql.PreparedStatement;

/**
 * sh使用preparedStatement实现批量操作
 * <p>
 * update,delete本身就具有批量操作的效果
 * insert 高效批量插入
 */
/*
题目,,插入两万条数据
create TABLE goods{
	id INT PRIMARY KEY AUTO_INCREMENT,
	name varchar(25)
};


SELECT COUNT(*) FROM goods;
 */

public class InserTest {
    @Test
    public void testInsert() {
        Connection conn = null;
        PreparedStatement ps = null;
        try {
            conn = JDBCUtils.getConnection();
            String sql = "delete from goods where id = ?";
//            String sql = "insert into goods(name) values(?)";
            ps = conn.prepareStatement(sql);
            for (int i = 1; i <= 1000; i++) {
                ps.setObject(1, i);
                ps.execute();
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps);
        }
    }

    /*
    批量插入操作
    优化,事务,,提交,不允许自动提交数据
     */
    @Test
    public void testInsert2() {
        long start = System.currentTimeMillis();
        Connection conn = null;
        PreparedStatement ps = null;
        try {
            conn = JDBCUtils.getConnection();
//            String sql = "delete from goods where id = ?";
            String sql = "insert into goods(name) values(?)";
            ps = conn.prepareStatement(sql);
            for (int i = 1; i <= 1000000; i++) {
                ps.setObject(1, "name_"+i);
//                攒sql
                ps.addBatch();
                if (i % 500 == 0) {
                    //执行
                    ps.executeBatch();
                    //清空
                    ps.clearBatch();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps);
        }

        long end = System.currentTimeMillis();
        System.out.println(end-start);
    }

    /**
     * 终极方案
     */
    @Test
    public void testInsert3() {
        long start = System.currentTimeMillis();
        Connection conn = null;
        PreparedStatement ps = null;
        try {
            conn = JDBCUtils.getConnection();
//            String sql = "delete from goods where id = ?";
            String sql = "insert into goods(name) values(?)";
            //设置不允许自动提交数据
            conn.setAutoCommit(false);
            ps = conn.prepareStatement(sql);
            for (int i = 1; i <= 1000000; i++) {
                ps.setObject(1, "name_"+i);
//                攒sql
                ps.addBatch();
                if (i % 500 == 0) {
                    //执行
                    ps.executeBatch();
                    //清空
                    ps.clearBatch();
                }
            }

            //统一提交
            conn.commit();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            JDBCUtils.closeResource(conn, ps);
        }

        long end = System.currentTimeMillis();
        System.out.println(end-start);
    }
}
