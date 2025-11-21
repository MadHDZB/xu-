package com.xzb.pojo;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.LocalDateTime;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Clazz {
    private Integer id; // 班级ID
    private String name; // 班级名称
    private String room; // 教室
    private LocalDateTime beginDate; // 开课时间
    private LocalDateTime endDate; // 结课时间
    private Integer masterId; // 班主任
    private Integer subject; // 学科
    private LocalDateTime createTime; // 创建时间
    private LocalDateTime updateTime; // 修改时间

    private String masterName; // 班主任名称
    private String status; // 班级状态 - 未开班，在读，已结课
}
