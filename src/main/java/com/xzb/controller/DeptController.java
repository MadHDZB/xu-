package com.xzb.controller;

import com.xzb.anno.Log;
import com.xzb.pojo.Dept;
import com.xzb.pojo.Result;
import com.xzb.service.DeptService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Slf4j
@RequestMapping("/depts") // value: 映射的请求路径，在这里写了值，则方法的注释里就不用写value
@RestController
public class DeptController {

    @Autowired
    private DeptService deptService;

    //@RequestMapping(value = "/depts",method = RequestMethod.GET) // method: 指定请求的方式
    @GetMapping // 默认GET请求，不用额外指定请求方式     类似的有@PostMapping @DeleteMapping @PutMapping
    public Result list() {
        log.info("查询全部部门数据");
        List<Dept> deptList = deptService.findAll();
        return Result.success(deptList);
    }

    /**
     * 删除部门 - 前端传递的请求参数名与服务端方法形参名一致，直接传递即可
     */
    @Log
    @DeleteMapping
    public Result delete(Integer id) {  // 这里的@RequestParam省略了
        log.info("根据ID删除部门：{}", id);
        deptService.deleteById(id);
        return Result.success();
    }

    /**
     * 新增部门
     */
    @Log
    @PostMapping
    public Result insert(@RequestBody Dept dept) {
        log.info("新增部门：{}", dept);
        deptService.insert(dept);
        return Result.success();
    }

    /**
     * 根据ID查询部门
     */
    @GetMapping("/{id}")
    public Result getInfo(@PathVariable Integer id) {
        log.info("根据ID查询部门：{}", id);
        Dept dept = deptService.getById(id);
        return Result.success(dept);
    }

    /**
     * 修改部门
     */
    @Log
    @PutMapping
    public Result update(@RequestBody Dept dept) {
        log.info("修改部门：{}", dept);
        deptService.update(dept);
        return Result.success();
    }
}
