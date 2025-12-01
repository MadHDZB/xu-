package com.xzb.filter;

import com.xzb.utils.CurrentHolder;
import com.xzb.utils.JWTUtils;
import io.jsonwebtoken.Claims;
import jakarta.servlet.*;
import jakarta.servlet.annotation.WebFilter;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.extern.slf4j.Slf4j;

import java.io.IOException;

@Slf4j
@WebFilter(urlPatterns = "/*")
public class TokenFilter implements Filter {
    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest request = (HttpServletRequest) servletRequest;
        HttpServletResponse response = (HttpServletResponse) servletResponse;

        // 1.获取到请求的路径
        String requestURI = request.getRequestURI(); // 获取到资源访问路径 /emp/login

        // 2.判断是否是登录请求，如果路径中包含/login，说明是登录操作，直接放行
        if(requestURI.contains("login")){
            log.info("登录操作，放行");
            filterChain.doFilter(request, response);
            return;
        }

        // 3.获取请求头中的token
        String token = request.getHeader("token");

        // 4.判断token是否为空，如果为空，说明用户没有登录，返回错误信息（响应401状态码）
        if(token == null || token.isEmpty()){
            log.info("令牌为空，响应401");
            response.setStatus(401);
            return;
        }

        // 5.如果token存在，校验令牌，如果校验失败，则返回错误信息（响应401状态码）
        try {
          Claims claims  = JWTUtils.parseToken(token);
            Integer empId = Integer.valueOf(claims.get("id").toString());
            CurrentHolder.setCurrentId(empId); // 存入
            log.info("当前登录用户ID：{}，将其存入ThreadLocal", empId);
        } catch (Exception e) {
            log.info("令牌校验失败，响应401");
            response.setStatus(401);
            return;
        }

        // 6.如果校验成功，则放行
        log.info("令牌校验成功，放行");
        filterChain.doFilter(request, response);

        // 7.删除ThreadLocal中的数据
        CurrentHolder.remove();
    }
}
