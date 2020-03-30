package mapper;


import entity.Comment;
import entity.Scene;
import entity.Visitor;

import java.util.List;
import java.util.Map;

/**
 * @author zkw
 * @date 2019/10/31 13:18
 */
public interface BaseMapper {
    List<Scene> listSceneInfo(Map<String,Object> params);

    Visitor getUserInfo(Map<String,Object> params);

    Integer getLikeCount(Map<String,Object> params);

    Integer insertLike(Map<String,Object> params);

    Integer insertComment(Map<String,Object> params);

    Integer deleteLike(Map<String,Object> params);

    Scene getSceneInfoById(Integer id);

    List<Comment> listCommentsBySceneId(Integer id);
}
