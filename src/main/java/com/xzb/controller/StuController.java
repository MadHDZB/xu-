package com.xzb.controller;

import com.xzb.pojo.PageResult;
import com.xzb.pojo.Result;
import com.xzb.pojo.StuQueryParam;
import com.xzb.pojo.Student;
import com.xzb.service.StuService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Slf4j
@RestController
@RequestMapping("/students")
public class StuController {
    @Autowired
    private StuService stuService;

    @GetMapping
    public Result page(StuQueryParam stuQueryParam){
        log.info("分页查询：{}",stuQueryParam);
        PageResult<Student> pageResult = stuService.page(stuQueryParam);
        return Result.success(pageResult);
    }

    @DeleteMapping("/{ids}")
    public Result deleteByIds(@PathVariable List<Integer> ids){
        log.info("批量删除：{}", ids);
        stuService.deleteByIds(ids);
        return Result.success();
    }

    @PostMapping
    public Result insert(@RequestBody Student stu){
        log.info("新增学员：{}", stu);
        stuService.insert(stu);
        return Result.success();
    }

    @GetMapping("/{id}")
    public Result queryById(@PathVariable Integer id){
        log.info("根据ID查询：{}", id);
        Student student = stuService.queryById(id);
        return Result.success(student);
    }

    @PutMapping
    public Result updateById(@RequestBody Student stu){
        stuService.updateById(stu);
        return Result.success();
    }

    @PutMapping("/violation/{id}/{score}")
    public Result updateScore(@PathVariable Integer id, @PathVariable Integer score){
        stuService.updateScore(id, score);
        return Result.success();
    }
}
