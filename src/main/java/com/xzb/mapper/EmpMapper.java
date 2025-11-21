package com.xzb.mapper;

import com.xzb.pojo.Emp;
import com.xzb.pojo.EmpQueryParam;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * 员工信息
 */
@Mapper
public interface EmpMapper {

    /**
     * 条件查询员工信息
     */
     List<Emp> list(EmpQueryParam empQueryParam);

    /**
     * 新增员工基本信息
     */
     @Insert("insert into emp(username, name, gender, phone, job, salary, image, entry_date, dept_id, create_time, update_time)" +
             "values (#{username}), #{name}, #{gender}, #{phone}, #{job}, #{salary}, #{image}, #{entryDate}, #{deptId}, #{createTime}, #{updateTime}")
    void insert(Emp emp);
}
