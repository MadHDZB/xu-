package com.xzb.mapper;

import com.xzb.pojo.ClazzCountOption;
import com.xzb.pojo.StuCountOption;
import com.xzb.pojo.StuQueryParam;
import com.xzb.pojo.Student;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Map;

@Mapper
public interface StuMapper {

    List<Student> list(StuQueryParam stuQueryParam);

    void deleteByIds(List<Integer> ids);

    void insert(Student stu);

    Student queryById(Integer id);

    void update(Student stu);

    void updateScore(Integer id, Integer score);

    List<StuCountOption> countStuDegreeData();

    List<Map<String, Object>> countClazzCountData();
}
