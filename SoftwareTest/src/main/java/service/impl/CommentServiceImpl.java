package service.impl;

import DB.DBUtil;
import entity.Comment;
import service.CommentService;

import java.sql.SQLException;
import java.util.List;

public class CommentServiceImpl implements CommentService {
  @Override
  public boolean addComment(String username, int infoId, String content) throws SQLException {
    if(DBUtil.insertComment(username,infoId,content) == 1){
      if(DBUtil.updateInfoCommentNums(infoId) != 1){
        System.out.println("更新评论数据失败！");
        return false;
      }
      System.out.println("更新评论数据成功！");
      return true;
    }
    return false;
  }

  @Override
  public List<Comment> showComment(int infoId) throws SQLException {
    return DBUtil.selectComment(infoId);
  }
}
