package com.xzb.service;

import com.xzb.pojo.Emp;
import com.xzb.pojo.PageResult;

public interface EmpService {
    public PageResult<Emp> page(Integer page, Integer pageSize );
}
