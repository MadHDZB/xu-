package com.xzb.mapper;

import com.xzb.pojo.Clazz;
import com.xzb.pojo.ClazzQueryParam;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface ClazzMapper {
    List<Clazz> list(ClazzQueryParam clazzQueryParam);

    @Delete("delete from clazz where id = #{id}")
    void deleteById(Integer id);

    void insert(Clazz clazz);

    @Select("select * from clazz where id = #{id}")
    Clazz queryById(Integer id);

    void updateById(Clazz clazz);

    List<Clazz> queryAll();
}
