package com.xzb.service;

import com.xzb.pojo.User;

import java.util.List;

public interface UserService {

    /**
     * 查询所有用户信息
     */
    public List<User> findAll();
}
