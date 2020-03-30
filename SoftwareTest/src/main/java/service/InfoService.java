package service;

import entity.info;

import java.sql.SQLException;
import java.util.List;

public interface InfoService {

  //得到全部旅游信息
  /**
   *
   * @param type 0-正常搜索，1-按点赞数排序，2-按评论数排序
   * @return
   */
  List<info> getInfoList(int type) throws SQLException;
  //通过id查找某景点的信息
  info getById(int id);

  /**
   *
   * @param text
   * @param type 0-正常搜索，1-按点赞数排序，2-按评论数排序
   * @return
   */
  List<info> getBySearch(String text, int type) throws SQLException;


}
