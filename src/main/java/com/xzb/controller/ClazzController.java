package com.xzb.controller;

import com.xzb.pojo.Clazz;
import com.xzb.pojo.ClazzQueryParam;
import com.xzb.pojo.PageResult;
import com.xzb.pojo.Result;
import com.xzb.service.ClazzService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Slf4j
@RestController
@RequestMapping("/clazzs")
public class ClazzController {
    @Autowired
    private ClazzService clazzService;

    @GetMapping
    public Result page(ClazzQueryParam clazzQueryParam){
        log.info("分页查询：{}", clazzQueryParam);
        PageResult<Clazz> pageResult = clazzService.getPageResult(clazzQueryParam);
        return Result.success(pageResult);
    }

    @DeleteMapping("{id}")
    public Result deleteById(@PathVariable Integer id){
        log.info("根据id删除班级：{}", id);
        clazzService.deleteByid(id);
        return Result.success();
    }

    @PostMapping
    public Result insert(@RequestBody Clazz clazz){
        log.info("新增班级：{}", clazz);
        clazzService.insert(clazz);
        return Result.success();
    }

    @GetMapping("{id}")
    public Result queryById(@PathVariable Integer id){
        log.info("根据id查询：{}", id);
        Clazz clazz = clazzService.queryById(id);
        return Result.success(clazz);
    }

    @PutMapping
    public Result updateById(@RequestBody Clazz clazz){
        log.info("修改班级：{}", clazz);
        clazzService.updateById(clazz);
        return Result.success();
    }

    @GetMapping("/list")
    public Result queryAll(){
        log.info("查询所有班级");
        List<Clazz> list = clazzService.queryAll();
        return Result.success(list);
    }
}
