package com.xzb.pojo;

import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

@Data
public class LogQueryParam {
    private Integer page = 1; // 页码
    private Integer pageSize = 10; // 每页展示记录数
}
