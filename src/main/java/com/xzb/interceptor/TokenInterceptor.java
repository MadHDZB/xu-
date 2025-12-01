package com.xzb.interceptor;

import com.xzb.utils.JWTUtils;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

/**
 * 令牌校验拦截器
 */
@Slf4j
@Component
public class TokenInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {

//        // 1.获取到请求的路径
//        String requestURI = request.getRequestURI(); // 获取到资源访问路径 /emp/login
//
//        // 2.判断是否是登录请求，如果路径中包含/login，说明是登录操作，直接放行
//        if(requestURI.contains("login")){
//            log.info("登录操作，放行");
//            return true;
//        }

        // 上面的功能在config类中调用方法实现了，在这里可以省掉

        // 3.获取请求头中的token
        String token = request.getHeader("token");

        // 4.判断token是否为空，如果为空，说明用户没有登录，返回错误信息（响应401状态码）
        if(token == null || token.isEmpty()){
            log.info("令牌为空，响应401");
            response.setStatus(401);
            return false;
        }

        // 5.如果token存在，校验令牌，如果校验失败，则返回错误信息（响应401状态码）
        try {
            JWTUtils.parseToken(token);
        } catch (Exception e) {
            log.info("令牌校验失败，响应401");
            response.setStatus(401);
            return false;
        }

        // 6.如果校验成功，则放行
        log.info("令牌校验成功，放行");
        return true;
    }
}
