package service.impl;

import DB.DBConnection;
import DB.DBUtil;
import entity.image;
import entity.info;
import service.InfoService;

import java.awt.*;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class InfoServiceImpl implements InfoService {
  @Override
  public List<info> getInfoList(int type) throws SQLException {
    String sql1 ;
    if(type == 0){
      sql1 = "select * from info";
      return DBUtil.showInfos(sql1);
    }
    else if(type == 1){
      sql1 = "select * from info order by like desc ";
      return DBUtil.showInfos(sql1);

    }
    else if(type == 2){
      sql1 = "select * from info order by comment_counts desc";
      return DBUtil.showInfos(sql1);
    }else {
      System.out.println("type类型错误");
      return null;
    }
  }

  @Override
  public info getById(int id) {
    String sql1 = "select * from info where id = " + id,sql2;
    info in = new info();
    try{
      PreparedStatement pstmt1 = null,pstmt2 = null;
      pstmt1=DBConnection.connection().prepareStatement(sql1);
      ResultSet rs1=pstmt1.executeQuery(),rs2 = null;
      if(rs1.next()){
        List<image> images = new ArrayList<>();
        in.setId(rs1.getInt("id"));
        in.setName(rs1.getString("name"));
        in.setLike(rs1.getInt("like"));
        in.setLocation(rs1.getString("location"));
        in.setOpenTime(rs1.getString("open_time"));
        in.setTime(rs1.getString("time"));
        in.setTicket(rs1.getString("ticket"));
        in.setTraffic(rs1.getString("traffic"));
        in.setSummary(rs1.getString("summary"));
        in.setCommentNums(rs1.getInt("comment_counts"));
        sql2 = "select * from image where info_id = " + in.getId();
        pstmt2 = DBConnection.connection().prepareStatement(sql2);
        rs2 = pstmt2.executeQuery();
        while (rs2.next()){
          image im = new image();
          im.setId(rs2.getInt("id"));
          im.setInfoId(rs2.getInt("info_id"));
          im.setUrl("/images/" + rs2.getString("url") + ".jpg");
          images.add(im);
        }
        in.setImages(images);
        System.out.println(in.toString());
      }
     DBConnection.connection().close();
    }catch (Exception e){
      throw new RuntimeException(e);
    }
    return in;
  }

  @Override
  public List<info> getBySearch(String text,int type) throws SQLException {
    if(text.equals("")) return getInfoList(type);
    String sql1 ;
    if(type == 0){
      sql1 = "select * from info where name  like '%\" + text + \"%'";
      return DBUtil.showInfos(sql1);
    }
    else if(type == 1){
      sql1 = "select * from info where name  like '%\" + text + \"%'order by like desc ";
      return DBUtil.showInfos(sql1);
    }
    else if(type == 2){
      sql1 = "select * from info where name  like '%\" + text + \"%' order by comment_counts desc";
      return DBUtil.showInfos(sql1);
    }
    else{
      System.out.println("type类型错误！");
      return null;
    }
  }

}
