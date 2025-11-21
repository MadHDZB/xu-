package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.EmpExprMapper;
import com.xzb.mapper.EmpMapper;
import com.xzb.pojo.Emp;
import com.xzb.pojo.EmpExpr;
import com.xzb.pojo.EmpQueryParam;
import com.xzb.pojo.PageResult;
import com.xzb.service.EmpService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.CollectionUtils;

import java.time.LocalDateTime;
import java.util.Collection;
import java.util.List;

@Service
public class EmpServiceImpl implements EmpService {

    @Autowired
    private EmpMapper empMapper;
    @Autowired
    private EmpExprMapper empExprMapper;

    /**
     * PageHelper实现分页查询
     *  page 页码
     *  pageSize 每页记录数
     */
    @Override
    public PageResult<Emp> page(EmpQueryParam empQueryParam) {
        // 1.设置分页参数(PageHelper)：查询哪一页数据，每页展示多少条记录
        PageHelper.startPage(empQueryParam.getPage(), empQueryParam.getPageSize());

        // 2.执行查询
        List<Emp> emplist = empMapper.list(empQueryParam);

        // 3.解析查询结果，并返回数据
        Page<Emp> p = (Page<Emp>) emplist;  // 能强转是因为Page实现了ArrayList，ArrayList又是实现了List，所以Page实际上是List子类
        return new PageResult<Emp>(p.getTotal(), p.getResult());
    }

    @Override
    public void save(Emp emp) {
        // 1.保存员工的基本信息
        emp.setUpdateTime(LocalDateTime.now());
        emp.setCreateTime(LocalDateTime.now());
        empMapper.insert(emp);
        // 2.保存员工的工作经历信息
        List<EmpExpr> exprList = emp.getExprList();
        if(!CollectionUtils.isEmpty(exprList)){
            empExprMapper.insertBatch(exprList);
        }
    }
}
