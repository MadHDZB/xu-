package com.xzb.mapper;

import com.xzb.pojo.LogQueryParam;
import com.xzb.pojo.OperateLog;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface LogMapper {
    @Select("select o.*, emp.name operateEmpName " +
            "from operate_log o left join emp on o.operate_emp_id = emp.id")
    List<OperateLog> list(LogQueryParam logQueryParam);
}
