package DB;

import entity.Comment;
import entity.image;
import entity.info;
import org.springframework.jdbc.support.xml.SqlXmlFeatureNotImplementedException;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class DBUtil {
  private static Connection conn = null;
  private static PreparedStatement ps = null;
  private static ResultSet rs = null;
  private static PreparedStatement pss = null;
  private static ResultSet rss = null;

  public static List<info> showInfos(String sql) throws SQLException {
    conn = DBConnection.connection();
    List<info> list = new ArrayList<>();
    String sql2 = null;
    try{
      ps = conn.prepareStatement(sql);
      rs = ps.executeQuery();
      while(rs.next()){
        info i = new info();
        List<image> images = new ArrayList<>();
        i.setId(rs.getInt("id"));
        i.setName(rs.getString("name"));
        i.setLike(rs.getInt("like"));
        i.setLocation(rs.getString("location"));
        i.setOpenTime(rs.getString("open_time"));
        i.setTime(rs.getString("time"));
        i.setTicket(rs.getString("ticket"));
        i.setTraffic(rs.getString("traffic"));
        i.setSummary(rs.getString("summary"));
        i.setCommentNums(rs.getInt("comment_counts"));
        sql2 = "select * from image where info_id = " + i.getId();
        pss = DBConnection.connection().prepareStatement(sql2);
        rss =  pss.executeQuery();
        while (rss.next()){
          image im = new image();
          im.setId(rss.getInt("id"));
          im.setInfoId(rss.getInt("info_id"));
          im.setUrl("/images/" + rss.getString("url") + ".jpg");
          images.add(im);
        }
        i.setImages(images);
        System.out.println(i.toString());
        list.add(i);
      }
    }catch (SQLException e){
      e.printStackTrace();
    }finally {
      conn.close();
    }
    return list;
  }

  public static int insertComment(String username, int infoId, String content) throws SQLException {
    conn = DBConnection.connection();
    Date now = new Date();
    SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    String nowString = simpleDateFormat.format(now);
    String sql = "insert into comments(username,info_id,content,create_time) values(?,?,?,?)";
    int i = -1;
    try {
      ps = conn.prepareStatement(sql);
      ps.setString(1, username);
      ps.setInt(2, infoId);
      ps.setString(3, content);
      ps.setString(4, nowString);
      i = ps.executeUpdate();
    }catch (SQLException e) {
      e.printStackTrace();
    }finally {
      conn.close();
    }
     return i;
  }

  public static int updateInfoCommentNums(int infoId) throws SQLException {
    int i= -1;
    conn = DBConnection.connection();
    String sql = "update info set comment_counts = comment_counts + 1 where id = "+ infoId ;
    try {
      ps = conn.prepareStatement(sql);
      i = ps.executeUpdate();
    }catch (SQLException e) {
      e.printStackTrace();
    }finally {
      conn.close();
    }
    return i;
  }

  public static List<Comment> selectComment(int infoId) throws SQLException{
    conn = DBConnection.connection();
    List<Comment> list = new ArrayList<>();
    String sql = "select * from comments where info_id = " + infoId;
    try {
      ps = conn.prepareStatement(sql);
      rs = ps.executeQuery();
      while (rs.next()){
        Comment comment = new Comment();
        comment.setId(rs.getInt("id"));
        comment.setUsername(rs.getString("username"));
        comment.setInfoId(rs.getInt("info_id"));
        comment.setContent(rs.getString("content"));
        comment.setCreateTime(rs.getString("create_time"));
        list.add(comment);
      }
    }catch (SQLException e){
      e.printStackTrace();
    }finally {
      conn.close();
    }
    return list;
  }

}
