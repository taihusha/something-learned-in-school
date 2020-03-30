package service;

import entity.Comment;
import entity.info;

import java.sql.SQLException;
import java.util.List;

public interface CommentService {
  //添加评论并更新评论数量
  boolean addComment(String username, int infoId, String content) throws SQLException;
  //显示某景点的评论
  List<Comment> showComment(int info_id) throws SQLException;
}
