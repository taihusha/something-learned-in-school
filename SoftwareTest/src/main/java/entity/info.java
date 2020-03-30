package entity;

import java.util.List;

public class info {


  public String getSummary() {
    return summary;
  }

  public void setSummary(String summary) {
    this.summary = summary;
  }
  private int id;
  //景点名称
  private String name;
  //景点介绍
  private String summary;
  //建议游览时间
  private String time;
  //交通指南
  private String traffic;
  //门票信息
  private String ticket;
  //景点开放时间
  private String openTime;
  //点赞数
  private int like;
  //景点地址
  private String location;
  //景点对应的图片
  private List<image> images;
  //景点对应评论数量
  private int commentNums;

  @Override
  public String toString() {
    return "info{" +
        "id=" + id +
        ", name='" + name + '\'' +
        ", summary='" + summary + '\'' +
        ", time='" + time + '\'' +
        ", traffic='" + traffic + '\'' +
        ", ticket='" + ticket + '\'' +
        ", openTime='" + openTime + '\'' +
        ", like=" + like +
        ", location='" + location + '\'' +
        ", images=" + images +
        ", commentNums=" + commentNums +
        '}';
  }

  public int getCommentNums() {
    return commentNums;
  }

  public void setCommentNums(int commentNums) {
    this.commentNums = commentNums;
  }



  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getTime() {
    return time;
  }

  public void setTime(String time) {
    this.time = time;
  }

  public String getTraffic() {
    return traffic;
  }

  public info() {
  }

  public void setTraffic(String traffic) {
    this.traffic = traffic;
  }

  public String getTicket() {
    return ticket;
  }

  public void setTicket(String ticket) {
    this.ticket = ticket;
  }

  public String getOpenTime() {
    return openTime;
  }

  public void setOpenTime(String openTime) {
    this.openTime = openTime;
  }

  public int getLike() {
    return like;
  }

  public void setLike(int like) {
    this.like = like;
  }

  public String getLocation() {
    return location;
  }

  public void setLocation(String location) {
    this.location = location;
  }

  public List<image> getImages() {
    return images;
  }

  public void setImages(List<image> images) {
    this.images = images;
  }

  public info(int id, String name,String summary, String time, String traffic, String ticket, String openTime, int like, String location, List<image> images) {
    this.id = id;
    this.name = name;
    this.summary=summary;
    this.time = time;
    this.traffic = traffic;
    this.ticket = ticket;
    this.openTime = openTime;
    this.like = like;
    this.location = location;
    this.images = images;
  }

  public info(int id, String name,String summary, String time, String traffic, String ticket, String openTime, int like, String location) {
    this.id = id;
    this.name = name;
    this.time = time;
    this.summary=summary;
    this.traffic = traffic;
    this.ticket = ticket;
    this.openTime = openTime;
    this.like = like;
    this.location = location;
  }
}
