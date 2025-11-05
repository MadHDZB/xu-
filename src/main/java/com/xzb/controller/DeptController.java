package com.xzb.controller;

import com.xzb.pojo.Dept;
import com.xzb.pojo.Result;
import com.xzb.service.DeptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class DeptController {

    @Autowired
    private DeptService deptService;

    //@RequestMapping(value = "/depts",method = RequestMethod.GET) // method: 指定请求的方式
    @GetMapping("/depts") // 默认GET请求，不用额外指定请求方式     类似的有@PostMapping @DeleteMapping @PutMapping
    public Result list() {
        System.out.println("查询全部部门数据");
        List<Dept> deptList = deptService.findAll();
        return Result.success(deptList);
    }

    /**
     * 删除部门 - 前端传递的请求参数名与服务端方法形参名一致，直接传递即可
     */
    @DeleteMapping("/depts")
    public Result delete(Integer id) {
        System.out.println("删除部门：" + id);
        deptService.deleteById(id);
        return Result.success();
    }

    /**
     * 新增部门
     */
    @PostMapping("/depts")
    public Result add(@RequestBody Dept dept) {
        System.out.println("新增部门：" + dept);
        deptService.add(dept);
        return Result.success();
    }
}
