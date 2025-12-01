package com.xzb.service.impl;

import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;
import com.xzb.mapper.EmpMapper;
import com.xzb.mapper.LogMapper;
import com.xzb.pojo.LogQueryParam;
import com.xzb.pojo.OperateLog;
import com.xzb.pojo.PageResult;
import com.xzb.service.LogService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class LogServiceImpl implements LogService {
    @Autowired
    private LogMapper logMapper;
    @Autowired
    private EmpMapper empMapper;

    @Override
    public PageResult<OperateLog> page(LogQueryParam logQueryParam) {
        PageHelper.startPage(logQueryParam.getPage(), logQueryParam.getPageSize());
        List<OperateLog> list = logMapper.list(logQueryParam);
        Page<OperateLog> page = (Page<OperateLog>) list;
        return new PageResult<>(page.getTotal(), page.getResult());
    }
}
