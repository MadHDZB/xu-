package com.sky.service;

import com.sky.dto.*;
import com.sky.result.PageResult;
import com.sky.vo.OrderPaymentVO;
import com.sky.vo.OrderStatisticsVO;
import com.sky.vo.OrderSubmitVO;
import com.sky.vo.OrderVO;

public interface OrderService {
    /**
     * 用户下单
     * @param ordersSubmitDTO
     * @return
     */
    OrderSubmitVO submitOrder(OrdersSubmitDTO ordersSubmitDTO);

    /**
     * 订单支付
     * @param ordersPaymentDTO
     * @return
     */
    OrderPaymentVO payment(OrdersPaymentDTO ordersPaymentDTO) throws Exception;

    /**
     * 支付成功，修改订单状态
     * @param outTradeNo
     */
    void paySuccess(String outTradeNo);

    /**
     * 查询各个状态的订单
     * @return
     */
    OrderStatisticsVO getOrderStatistics();

    /**
     * 完成订单
     * @param id
     */
    void completeOrder(Long id);

    /**
     * 拒单
     * @param ordersRejectionDTO
     */
    void rejectOrder(OrdersRejectionDTO ordersRejectionDTO);

    /**
     * 取消订单
     * @param ordersCancelDTO
     */
    void cancelOrder(OrdersCancelDTO ordersCancelDTO);

    /**
     * 接单
     * @param ordersConfirmDTO
     */
    void confirmOrder(OrdersConfirmDTO ordersConfirmDTO);

    /**
     * 获取订单详情
     * @param id
     * @return
     */
    OrderVO getOrderDetails(Long id);

    /**
     * 派送订单
     * @param id
     */
    void deliverOrder(Long id);

    /**
     * 订单分页查询
     * @param ordersPageQueryDTO
     * @return
     */
    PageResult pageQuery(OrdersPageQueryDTO ordersPageQueryDTO);

    /**
     * 用户端订单分页查询
     */
    PageResult pageQueryForUser(OrdersPageQueryDTO ordersPageQueryDTO);

    /**
     * 用户取消订单
     * @param id
     */
    void userCancelOrder(Long id);

    /**
     * 再来一单
     * @param id
     */
    void repeat(Long id);

    /**
     * 用户催单
     * @param id
     */
    void push(Long id);
}
