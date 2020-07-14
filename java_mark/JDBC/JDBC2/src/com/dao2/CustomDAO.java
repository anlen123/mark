package com.dao2;

import com.bean.Customer;

import java.sql.Connection;
import java.sql.Date;
import java.util.List;

/*
 * 此接口用于规范对于Customer表的操作
 */
public interface CustomDAO {
    /** 
     * @Author: *华强
     * @Description //TODO 将cust对象添加到数据库中
     * @Date 11:59 2020/6/14
     * @Param [con, cust]
     * @return void
     **/
    void insert(Connection conn, Customer cust);
    /** 
     * @Author: *华强
     * @Description //TODO 删除表中的一个ID的数据
     * @Date 12:01 2020/6/14
     * @Param [conn, id]
     * @return void
     **/
    void deleteById(Connection conn,int id);
    
    /** 
     * @Author: *华强
     * @Description //TODO 修改对象
     * @Date 12:01 2020/6/14
     * @Param [conn, id]
     * @return void
     **/
    void update(Connection conn,Customer cust);
    /** 
     * @Author: *华强
     * @Description //TODO 针对客户id查询得到客户数据
     * @Date 12:02 2020/6/14
     * @Param [conn, id]
     * @return void
     **/
    Customer getCustomerById(Connection conn,int id);
    
    /** 
     * @Author: *华强
     * @Description //TODO 查询表中的所有数据
     * @Date 12:03 2020/6/14
     * @Param [conn]
     * @return java.util.List<com.bean.Customer>
     **/
    List<Customer> getAll(Connection conn);
    
    /** 
     * @Author: *华强
     * @Description //TODO 返回数据表中数据的条目数
     * @Date 12:04 2020/6/14
     * @Param [conn]
     * @return java.lang.Long
     **/
    Long getCount(Connection conn);

    /**
     * @Author: *华强
     * @Description //TODO 返回数据表中生日最大的日期
     * @Date 12:05 2020/6/14
     * @Param [conn]
     * @return java.util.Date
     **/
    Date getMaxBirth(Connection conn);

}
