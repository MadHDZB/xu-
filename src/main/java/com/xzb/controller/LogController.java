package com.xzb.controller;

import com.xzb.pojo.LogQueryParam;
import com.xzb.pojo.OperateLog;
import com.xzb.pojo.PageResult;
import com.xzb.pojo.Result;
import com.xzb.service.LogService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Slf4j
@RestController
public class LogController {
    @Autowired
    private LogService logService;
    /**
     * 分页查询日志
     */
    @GetMapping("/log/page")
    public Result page(LogQueryParam logQueryParam){
        log.info("分页查询：{}", logQueryParam);
        PageResult<OperateLog> pageResult = logService.page(logQueryParam);
        return Result.success(pageResult);
    }
}
