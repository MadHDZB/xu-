package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.EmpExprMapper;
import com.xzb.mapper.EmpMapper;
import com.xzb.pojo.*;
import com.xzb.service.EmpService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;

import java.time.LocalDateTime;
import java.util.Arrays;
import java.util.List;

@Slf4j
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
    @Transactional(rollbackFor = {Exception.class}) // 事务管理 -- 默认出现运行时异常RuntimeException才会回滚事务
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
        List<EmpExpr> exprList = emp.getExprList(); // 前端传过来的值已经封装到emp对象中了，直接调用方法即可获取
        if(!CollectionUtils.isEmpty(exprList)){
            // 遍历集合，为empId赋值  在第一步操作中使用主键返回了，所以emp.getId()获取该员工id值，赋值给empExpr
            // 用于对应他的工作经历，否则工作经历表中的数据无人对应（这就是逻辑外键）
            exprList.forEach(empExpr ->{
                empExpr.setEmpId(emp.getId());
            });
            empExprMapper.insertBatch(exprList);
        }
    }

    @Transactional(rollbackFor = {Exception.class})
    @Override
    public void delete(List<Integer> ids) {
        // 1.批量删除员工基本信息
        empMapper.deleteByIds(ids);

        // 2.批量删除员工工作经历信息
        empExprMapper.deleteByEmpIds(ids);
    }

    @Override
    public Emp getInfo(Integer id) {
        return empMapper.getById(id);
    }

    @Transactional(rollbackFor = {Exception.class})
    @Override
    public void update(Emp emp) {
        // 1.根据ID修改员工基本信息
        emp.setUpdateTime(LocalDateTime.now());
        empMapper.updateById(emp);

        // 2.根据ID修改员工工作经历信息
        // 2.1 先根据员工ID删除原有工作经历
        empExprMapper.deleteByEmpIds(Arrays.asList(emp.getId()));

        // 2.2 再添加这个员工新的工作经历
        List<EmpExpr> exprList = emp.getExprList();
        if(!CollectionUtils.isEmpty(exprList)){
            // 遍历集合，为empId赋值
            exprList.forEach(empExpr ->{
                empExpr.setEmpId(emp.getId());
            });
            empExprMapper.insertBatch(exprList);
        }
    }

    @Override
    public List<Emp> queryAll() {
        return empMapper.queryAll();
    }

    @Override
    public LoginInfo login(Emp emp) {
        // 1.调用mapper接口，根据用户名和密码查询员工信息
        Emp e = empMapper.selectByUsernameAndPassword(emp);

        // 2.判断：判断是否存在这个员工，如果存在，组装登陆成功信息
        if(e != null){
            log.info("员工登陆成功：{}", e);
            return new LoginInfo(e.getId(), e.getUsername(), e.getName(), "");
        }

        // 3.不存在，返回null
        return null;
    }
}