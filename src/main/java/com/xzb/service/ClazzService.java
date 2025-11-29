package com.xzb.service;

import com.xzb.pojo.Clazz;
import com.xzb.pojo.ClazzQueryParam;
import com.xzb.pojo.PageResult;

import java.util.List;

public interface ClazzService {

    PageResult<Clazz> getPageResult(ClazzQueryParam clazzQueryParam);

    void deleteByid(Integer id);

    void insert(Clazz clazz);

    Clazz queryById(Integer id);

    void updateById(Clazz clazz);

    List<Clazz> queryAll();
}
