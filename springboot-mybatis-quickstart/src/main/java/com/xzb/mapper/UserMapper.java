package com.xzb.mapper;

import com.xzb.pojo.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper // 应用程序在运行时，会自动为该接口创建一个实现类对象（代理对象），并且会将代理对象交给IOC容器管理 - bean
public interface UserMapper {

    @Select("SELECT * FROM employee")
    public List<User> findAll();
}
