package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.StuMapper;
import com.xzb.pojo.PageResult;
import com.xzb.pojo.StuQueryParam;
import com.xzb.pojo.Student;
import com.xzb.service.StuService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.util.List;

@Service
public class StuServiceImpl implements StuService {
    @Autowired
    private StuMapper stuMapper;

    @Override
    public PageResult<Student> page(StuQueryParam stuQueryParam) {
        PageHelper.startPage(stuQueryParam.getPage(), stuQueryParam.getPageSize());
        List<Student> list =stuMapper.list(stuQueryParam);
        Page<Student> page = (Page<Student>) list;
        return new PageResult<>(page.getTotal(), page.getResult());
    }

    @Override
    public void deleteByIds(List<Integer> ids) {
        stuMapper.deleteByIds(ids);
    }

    @Override
    public void insert(Student stu) {
        stu.setCreateTime(LocalDateTime.now());
        stu.setUpdateTime(LocalDateTime.now());
        stuMapper.insert(stu);
    }

    @Override
    public Student queryById(Integer id) {
        return stuMapper.queryById(id);
    }

    @Override
    public void updateById(Student stu) {
        stu.setUpdateTime(LocalDateTime.now());
        stuMapper.update(stu);
    }

    @Override
    public void updateScore(Integer id, Integer score) {
        stuMapper.updateScore(id, score);
    }
}
