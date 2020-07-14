package com.Blob;

import com.bean.Customer;
import com.sun.xml.internal.bind.v2.model.core.ID;
import com.util.JDBCUtils;
import org.hamcrest.core.Is;
import org.junit.Test;

import javax.naming.Name;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.sql.*;

public class BlobTest {
    /*
    Blob字段插入数据
     */
    @Test
    public void testInsert() throws Exception {
        Connection conn = JDBCUtils.getConnection();
        String sql  = "insert into customers(name,email,birth,photo) values(?,?,?,?)";
        PreparedStatement ps = conn.prepareStatement(sql);

        ps.setObject(1,"sdjgfdsh");
        ps.setObject(2,"176654@qq.com");
        ps.setObject(3,"2020-02-20");
        FileInputStream file = new FileInputStream(new File("2.jpg"));
        ps.setBlob(4,file);

        ps.execute();
        file.close();
        JDBCUtils.closeResource(conn,ps);
    }

    //查询数据表中的Blob字段

    @Test
    public void testQuery(){
        Connection conn = null;
        PreparedStatement ps = null;
        ResultSet rs = null;
        InputStream is = null;
        FileOutputStream fos = null;
        try {
            conn = JDBCUtils.getConnection();
            String sql = "select id,name,email,birth,photo from customers where id = ?";
            ps = conn.prepareStatement(sql);

            ps.setObject(1,28);

            rs = ps.executeQuery();
            if(rs.next()){
    //            int id = rs.getInt(1);
    //            String name = rs.getString(2);
    //            String email = rs.getString(3);
    //            Date birth = rs.getDate(4);
                int id = rs.getInt("id");
                String name = rs.getString("name");
                String email = rs.getString("email");
                Date birth = rs.getDate("birth");

                Customer cust = new Customer(id, name, email, birth);

                Blob photo = rs.getBlob("photo");
                //将blob字段下载下来,以文件的方式保存本地

                is = photo.getBinaryStream();
                fos = new FileOutputStream(new File("233.png"));

                byte[] bytes = new byte[1024];
                int len;
                while ((len =is.read(bytes))!=-1){
                    fos.write(bytes,0,len);
                }
                System.out.println(cust);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            try {
                if (is != null) {
                    is.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            try {
                if (fos != null) {
                    fos.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            JDBCUtils.closeResource(conn,ps,rs);
        }
    }



}
