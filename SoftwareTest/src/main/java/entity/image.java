package entity;

public class image {
  private int id;
  private int infoId;

  @Override
  public String toString() {
    return "image{" +
        "id=" + id +
        ", infoId=" + infoId +
        ", url='" + url + '\'' +
        '}';
  }

  private String url;

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public int getInfoId() {
    return infoId;
  }

  public void setInfoId(int infoId) {
    this.infoId = infoId;
  }

  public String getUrl() {
    return url;
  }

  public void setUrl(String url) {
    this.url = url;
  }

  public image(int id, int infoId, String url) {
    this.id = id;
    this.infoId = infoId;
    this.url = url;
  }
  public image(){

  }
}
