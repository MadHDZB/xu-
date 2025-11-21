package com.xzb.service;

import com.xzb.pojo.Emp;
import com.xzb.pojo.EmpQueryParam;
import com.xzb.pojo.PageResult;

import java.util.List;

public interface EmpService {
    PageResult<Emp> page(EmpQueryParam empQueryParam);

    /**
     * 保存
     */
    void save(Emp emp);

    /**
     * 批量删除
     */
    void delete(List<Integer> ids);

    /**
     * 根据ID查询员工信息
     */
    Emp getInfo(Integer id);

    /**
     * 修改员工
     */
    void update(Emp emp);
}
