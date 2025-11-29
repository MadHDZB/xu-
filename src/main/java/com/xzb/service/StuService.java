package com.xzb.service;

import com.xzb.pojo.PageResult;
import com.xzb.pojo.StuCountOption;
import com.xzb.pojo.StuQueryParam;
import com.xzb.pojo.Student;

import java.util.List;

public interface StuService {
    PageResult<Student> page(StuQueryParam stuQueryParam);

    void deleteByIds(List<Integer> ids);

    void insert(Student stu);

    Student queryById(Integer id);

    void updateById(Student stu);

    void updateScore(Integer id, Integer score);

}
