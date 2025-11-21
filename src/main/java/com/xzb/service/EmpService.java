package com.xzb.service;

import com.xzb.pojo.Emp;
import com.xzb.pojo.EmpQueryParam;
import com.xzb.pojo.PageResult;

public interface EmpService {
    PageResult<Emp> page(EmpQueryParam empQueryParam);

    void save(Emp emp);
}
