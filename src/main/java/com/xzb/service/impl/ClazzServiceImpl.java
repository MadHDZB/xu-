package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.ClazzMapper;
import com.xzb.pojo.Clazz;
import com.xzb.pojo.ClazzQueryParam;
import com.xzb.pojo.PageResult;
import com.xzb.service.ClazzService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;

@Service
public class ClazzServiceImpl implements ClazzService {
    @Autowired
    private ClazzMapper clazzMapper;

    @Override
    public PageResult<Clazz> getPageResult(ClazzQueryParam clazzQueryParam) {
        PageHelper.startPage(clazzQueryParam.getPage(), clazzQueryParam.getPageSize());
        List<Clazz> clazzlist = clazzMapper.list(clazzQueryParam);
        Page<Clazz> p = (Page<Clazz>) clazzlist;
        return new PageResult<>(p.getTotal(), p.getResult());
    }

    @Override
    public void deleteByid(Integer id) {
        clazzMapper.deleteById(id);
    }

    @Override
    public void insert(Clazz clazz) {
        clazz.setCreateTime(LocalDateTime.now());
        clazz.setUpdateTime(LocalDateTime.now());
        clazzMapper.insert(clazz);
    }

    @Override
    public Clazz queryById(Integer id) {
        Clazz clazz = clazzMapper.queryById(id);
        return clazz;
    }

    @Override
    public void updateById(Clazz clazz) {
        clazz.setUpdateTime(LocalDateTime.now());
        clazzMapper.updateById(clazz);
    }

    @Override
    public List<Clazz> queryAll() {
        return clazzMapper.queryAll();
    }
}
