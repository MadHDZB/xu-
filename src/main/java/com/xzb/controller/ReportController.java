package com.xzb.controller;

import com.xzb.pojo.ClazzCountOption;
import com.xzb.pojo.JobOption;
import com.xzb.pojo.Result;
import com.xzb.pojo.StuCountOption;
import com.xzb.service.ReportService;
import com.xzb.service.StuService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;
import java.util.Map;

@Slf4j
@RequestMapping("/report")
@RestController
public class ReportController {

    @Autowired
    private ReportService reportService;

    @GetMapping("/empJobData")
    public Result getEmpJobOption(){
        log.info("获取员工职位列表");
        JobOption jobOption = reportService.getEmpJobData();
        return Result.success(jobOption);
    }

    @GetMapping("/empGenderData")
    public Result getEmpGenderOption(){
        log.info("获取员工性别列表");
        List<Map<String, Object>> genderList = reportService.getEmpGenderData();
        return Result.success(genderList);
    }

    @GetMapping("/studentDegreeData")
    public Result getStuDegreeOption(){
        log.info("获取学员学历列表");
        List<StuCountOption> list = reportService.getStuDegreeData();
        return Result.success(list);
    }

    @GetMapping("/studentCountData")
    public Result getStuCountOption(){
        log.info("获取班级人数列表");
        ClazzCountOption clazzCountOption = reportService.getClazzCountData();
        return Result.success(clazzCountOption);
    }
}