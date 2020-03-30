package entity;

import java.util.List;

/**
 * @author zkw
 * @date 2019/11/1 9:59
 */
public class Scene {
    private Integer id;
    private String name;
    private String summary;
    private String time;
    private String traffic;
    private String ticket;
    private String openTime;
    private String location;
    private String likeNum;           // 点赞数量
    private String currUserLike;     // 当前用户是否点赞
    private String commentNum;        // 评论数量
    private String imageUrls;           // 景点图片的url

    public String getCurrUserLike() {
        return currUserLike;
    }

    public void setCurrUserLike(String currUserLike) {
        this.currUserLike = currUserLike;
    }

    public String getImageUrls() {
        return imageUrls;
    }

    public void setImageUrls(String imageUrls) {
        this.imageUrls = imageUrls;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSummary() {
        return summary;
    }

    public void setSummary(String summary) {
        this.summary = summary;
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

    public void setTraffic(String traffic) {
        this.traffic = traffic;
    }

    public String getTicket() {
        return ticket;
    }

    public void setTicket(String ticket) {
        this.ticket = ticket;
    }



    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public String getOpenTime() {
        return openTime;
    }

    public void setOpenTime(String openTime) {
        this.openTime = openTime;
    }

    public String getLikeNum() {
        return likeNum;
    }

    public void setLikeNum(String likeNum) {
        this.likeNum = likeNum;
    }


    public String getCommentNum() {
        return commentNum;
    }

    public void setCommentNum(String commentNum) {
        this.commentNum = commentNum;
    }

}
