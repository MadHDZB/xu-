package com.xzb;

import com.xzb.mapper.UserMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest // SpringBoot单元测试的注解 - 当前测试类中的测试方法运行时，会自动启动SpringBoot项目 - IOC容器
class SpringbootMybatisQuickstartApplicationTests {

    @Autowired
    private UserMapper userMapper;

    @Test
    public void testFindAll() {
        userMapper.findAll().forEach(System.out::println);
    }
}
