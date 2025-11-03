package com.xzb.controller;

import com.xzb.pojo.Dept;
import com.xzb.pojo.Result;
import com.xzb.service.DeptService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

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
}
