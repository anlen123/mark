package com.dao;

import com.bean.Customer;

import java.sql.Connection;
import java.sql.Date;
import java.util.List;

public class CustomerDAOimpl extends BaseDAO implements CustomDAO {

    @Override
    public void insert(Connection conn, Customer cust) {
        String sql = "insert into customers(name,email,birth) values(?,?,?)";
        int update = update(conn, sql, cust.getName(), cust.getEmail(), cust.getBirth());
//        System.out.println(update);
    }

    @Override
    public void deleteById(Connection conn, int id) {
        String sql = "delete from customers where id = ? ";
        int update = update(conn, sql, id);
    }

    @Override
    public void update(Connection conn, Customer cust) {
        String sql = "update customers set name = ?, email = ? ,birth = ? where id = ?";
        update(conn, sql, cust.getName(), cust.getEmail(), cust.getBirth(), cust.getId());
    }

    @Override
    public Customer getCustomerById(Connection conn, int id) {
        String sql = "select id,name,email,birth from customers where id = ? ";
        Customer customer = getInstance(conn, Customer.class, sql, id);
        return customer;
    }

    @Override
    public List<Customer> getAll(Connection conn) {
        String sql = "select id,name,email,birth from customers";
        List<Customer> list = getForList(conn, Customer.class, sql);
        return list;
    }

    @Override
    public Long getCount(Connection conn) {
        String sql = "select count(*) from customers";
        Long count = getValue(conn, sql);
        return count;
    }

    @Override
    public Date getMaxBirth(Connection conn) {
        String sql = "select max(birth) from customers";
        Date maxBirth = getValue(conn, sql);
        return maxBirth;
    }
}
