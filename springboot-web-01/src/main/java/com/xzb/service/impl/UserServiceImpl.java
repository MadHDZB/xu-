package com.xzb.service.impl;

import com.xzb.dao.UserDao;
import com.xzb.pojo.User;
import com.xzb.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

@Service // 将当前类交给IOC容器管理
public class UserServiceImpl implements UserService {

    @Autowired // 应用程序运行时，会自动查询该类型的bean对象，并赋值给该成员变量
    private UserDao userDao;
    @Override
    public List<User> findAll() {
        // 1.调用dao层方法，获取数据
        List<String> lines = userDao.findAll();

        // 2.解析用户信息，封装为User对象 -> list集合
        List<User> userList = lines.stream().map(line -> {
            String[] split = line.split(",");
            Integer id = Integer.parseInt(split[0]);
            String username = split[1];
            String password = split[2];
            String name = split[3];
            Integer age = Integer.parseInt(split[4]);
            LocalDateTime updateTime = LocalDateTime.parse(split[5], DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
            return new User(id, username, password, name, age, updateTime);
        }).toList();

        return userList;
    }
}
