package com.xzb.service;

import com.xzb.pojo.LogQueryParam;
import com.xzb.pojo.OperateLog;
import com.xzb.pojo.PageResult;

public interface LogService {
    PageResult<OperateLog> page(LogQueryParam logQueryParam);
}
