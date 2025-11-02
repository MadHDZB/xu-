package com.xzb;

import jakarta.servlet.http.HttpServletResponse;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;

@RestController
public class ResponseController {
    /**
     * 方式一：使用HttpServletResponse 设置响应数据
     */
    @RequestMapping("/response")
    public void response(HttpServletResponse response) throws IOException {
        // 1.设置响应状态码
        response.setStatus(202); // 一般不用设置，会自动响应200

        // 2.设置响应头
        response.setHeader("name", "徐佐滨");

        // 3.设置响应体
        response.getWriter().write("<h1>hello response</h1>"); // <h1>是HTML标签用来使文本以一级标题形式显示在网页上
    }


    /**
     * 方式二：使用ResponseEntity - Spring中提供的方式
     */
    @RequestMapping("/response2")
    public ResponseEntity<String> response2(){
        return ResponseEntity.status(401).header("name", "xzb")
                .body("<h1>hello response2</h1>");
    }
}
