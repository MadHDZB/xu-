package com.xzb.service;

import com.xzb.pojo.Dept;

import java.util.List;

public interface DeptService {
    /**
     * 查询所有部门数据
     */
    List<Dept> findAll();

    /**
     * 根据id删除部门
     */
    void deleteById(Integer id);

    void add(Dept dept);
}
