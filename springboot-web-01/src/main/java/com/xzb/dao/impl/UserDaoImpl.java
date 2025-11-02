package com.xzb.dao.impl;

import cn.hutool.core.io.IoUtil;
import com.xzb.dao.UserDao;
import org.springframework.stereotype.Repository;

import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

@Repository // 将当前类交给IOC容器管理
public class UserDaoImpl implements UserDao {
    @Override
    public List<String> findAll() {
        // 1.加载并读取user.txt类
        InputStream in = this.getClass().getClassLoader().getResourceAsStream("user.txt");
        ArrayList<String> lines = IoUtil.readLines(in, StandardCharsets.UTF_8, new ArrayList<>());
        return lines;
    }
}
