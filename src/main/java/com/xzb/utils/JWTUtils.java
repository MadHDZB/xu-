package com.xzb.utils;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;

import java.util.Date;
import java.util.Map;

public class JWTUtils {
    private static final String SECRET_KEY = "aXRoZWltYQ"; // 密钥
    private static final long EXPIRATION_TIME = 12 * 60 * 60 * 1000; // 过期时间

    /**
     * 生成JWT
     * @param claims 令牌中包含的信息
     * @return 生成的JWT
     */
    public static String generateToken(Map<String, Object> claims) {
        return Jwts.builder()
                .signWith(SignatureAlgorithm.HS256, SECRET_KEY)
                .addClaims(claims)
                .setExpiration(new Date(System.currentTimeMillis() + EXPIRATION_TIME))
                .compact();
    }

    /**
     * 解析JWT
     * @param token 要解析的JWT
     * @return 解析后的令牌信息
     */
    public static Claims parseToken(String token) {
        return Jwts.parser()
                .setSigningKey(SECRET_KEY)
                .parseClaimsJws(token)
                .getBody();
    }
}
