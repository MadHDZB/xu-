package com.xzb.controller;

import com.xzb.pojo.User;
import com.xzb.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import java.util.List;

@RestController // @ResponseBody作用：将controller返回值直接写入HTTP响应体；返回值是对象/集合，会自动转换为json数据
public class UserController{
//    @RequestMapping("/list")
//    public List<User> list() throws Exception{
//        // 1.加载并读取user.txt类
//        InputStream in = this.getClass().getClassLoader().getResourceAsStream("user.txt");
//        ArrayList<String> lines = IoUtil.readLines(in, StandardCharsets.UTF_8, new ArrayList<>());
//
//        // 2.解析用户信息，封装为User对象 -> list集合
//        List<User> userList = lines.stream().map(line -> {
//            String[] split = line.split(",");
//            Integer id = Integer.parseInt(split[0]);
//            String username = split[1];
//            String password = split[2];
//            String name = split[3];
//            Integer age = Integer.parseInt(split[4]);
//            LocalDateTime updateTime = LocalDateTime.parse(split[5], DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
//            return new User(id, username, password, name, age, updateTime);
//        }).toList();
//
//        // 3.返回数据（json）
//        return userList; // 服务器端返回数据，浏览器接收到数据，将数据解析为json，在页面展示
//    }



    @Autowired // 应用程序运行时，会自动查询该类型的bean对象，并赋值给该成员变量
    private UserService userService;

    @RequestMapping("/list")
    public List<User> list() throws Exception{
        // 1.调用service层方法，获取数据
        List<User> userList = userService.findAll();

        // 2.返回数据（json）
        return userList; // 服务器端返回数据，浏览器接收到数据，将数据解析为json，在页面展示
    }
}
