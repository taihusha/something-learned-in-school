package entity;

public class Comment {
  int id;
  String username;
  int infoId;
  String content;
  String createTime;

  @Override
  public String toString() {
    return "Comment{" +
        "id=" + id +
        ", username='" + username + '\'' +
        ", infoId=" + infoId +
        ", content='" + content + '\'' +
        ", createTime='" + createTime + '\'' +
        '}';
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getUsername() {
    return username;
  }

  public void setUsername(String username) {
    this.username = username;
  }

  public int getInfoId() {
    return infoId;
  }

  public void setInfoId(int infoId) {
    this.infoId = infoId;
  }

  public String getContent() {
    return content;
  }

  public void setContent(String content) {
    this.content = content;
  }

  public String getCreateTime() {
    return createTime;
  }

  public void setCreateTime(String createTime) {
    this.createTime = createTime;
  }

  public Comment() {
  }
}
