package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.EmpMapper;
import com.xzb.pojo.Emp;
import com.xzb.pojo.PageResult;
import com.xzb.service.EmpService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class EmpServiceImpl implements EmpService {

    @Autowired
    private EmpMapper empMapper;

    /**
     * PageHelper实现分页查询
     * @param page 页码
     * @param pageSize 每页记录数
     */
    @Override
    public PageResult<Emp> page(Integer page, Integer pageSize) {
        // 1.设置分页参数(PageHelper)：查询哪一页数据，每页展示多少条记录
        PageHelper.startPage(page, pageSize);

        // 2.执行查询
        List<Emp> emplist = empMapper.list();

        // 3.解析查询结果，并返回数据
        Page<Emp> p = (Page<Emp>) emplist;  // 能强转是因为Page实现了ArrayList，ArrayList又是实现了List，所以Page实际上是List子类
        return new PageResult<Emp>(p.getTotal(), p.getResult());
    }
}
