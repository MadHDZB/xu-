package com.xzb.service;

import com.xzb.pojo.JobOption;

import java.util.List;
import java.util.Map;

public interface ReportService {
    /**
     * 获取员工职位数据
     */
    JobOption getEmpJobData();

    /**
     * 获取员工性别数据
     */
    List<Map<String, Object>>  getEmpGenderData();
}
