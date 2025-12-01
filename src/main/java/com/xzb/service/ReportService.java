package com.xzb.service;

import com.xzb.pojo.ClazzCountOption;
import com.xzb.pojo.JobOption;
import com.xzb.pojo.StuCountOption;

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

    /**
     * 获取学员学历数据
     */
    List<StuCountOption> getStuDegreeData();

    /**
     * 获取班级人数数据
     */
    ClazzCountOption getClazzCountData();
}
