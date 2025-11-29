package com.xzb.service.impl;

import com.xzb.mapper.EmpMapper;
import com.xzb.mapper.StuMapper;
import com.xzb.pojo.ClazzCountOption;
import com.xzb.pojo.JobOption;
import com.xzb.pojo.StuCountOption;
import com.xzb.service.ReportService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Map;

@Service
public class ReportServiceImpl implements ReportService {
    @Autowired
    private EmpMapper empMapper;
    @Autowired
    private StuMapper stuMapper;

    @Override
    public JobOption getEmpJobData() {
        // 1.调用mapper接口获取统计数据
        List<Map<String, Object>> list = empMapper.countEmpJobData(); // map：pos=教研主管，num=1

        // 2.组装结果并返回
        List<Object> jobList = list.stream().map(dataMap -> dataMap.get("pos")).toList();
        List<Object> dataList = list.stream().map(dataMap -> dataMap.get("num")).toList();

        return new JobOption(jobList, dataList);
    }

    @Override
    public List<Map<String, Object>> getEmpGenderData() {
        return empMapper.countEmpGenderData();
    }

    @Override
    public List<StuCountOption> getStuDegreeData() {
        return stuMapper.countStuDegreeData();
    }

    @Override
    public ClazzCountOption getClazzCountData() {
        List<Map<String, Object>> list = stuMapper.countClazzCountData();
        List<Object> clazzList = list.stream().map(dataMap -> dataMap.get("cname")).toList();
        List<Object> dataList = list.stream().map(dataMap -> dataMap.get("count")).toList();
        return new ClazzCountOption(clazzList, dataList);
    }


}
