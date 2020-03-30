package service.impl;

import entity.Comment;
import entity.Scene;
import factory.SessionFactorySingleton;
import mapper.BaseMapper;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author zkw
 * @date 2019/10/31 13:04
 */


@Service
public class ZkwService {

    public Map<String,Object> praise(String userId, Integer sceneId) throws IOException {
        Map<String,Object> params = new HashMap<>();
        params.put("userId",userId);
        params.put("sceneId",sceneId);
        int count = 0;

        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            Integer curr_user_like_num = mapper.getLikeCount(params);       // 当前用户对该景点的点赞数量
            params.remove("userId");
            Integer scene_like_num = mapper.getLikeCount(params);           // 该景点所有的点赞数量
            params.put("userId",userId);

            if (curr_user_like_num > 0){       // 取消点赞
                count = mapper.deleteLike(params);
                params.put("type","0");
                params.put("like_num",scene_like_num-1);
            }else{              // 点赞
                count = mapper.insertLike(params);
                params.put("type","1");
                params.put("like_num",scene_like_num+1);
            }
        }

        if (count < 1){
            params.put("result","0");
            params.put("message","操作失败！");
        }else{
            params.put("result","1");
        }

        return params;
    }

    public List<Scene> listSceneInfo(Map<String, Object> params) throws IOException {
        List<Scene> scenes = null;
        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            scenes = mapper.listSceneInfo(params);
        }

        return scenes;
    }

    public Scene getSceneInfoById(Integer id) throws IOException {
        Scene scene = null;
        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            scene = mapper.getSceneInfoById(id);
        }

        return scene;
    }

    public List<Comment> getCommentsBySceneId(Integer id) throws IOException {
        List<Comment> comments = null;
        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            comments = mapper.listCommentsBySceneId(id);
        }

        return comments;
    }

    public int comment(Map<String, Object> params) throws IOException {
        int num = 0;
        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            num = mapper.insertComment(params);
        }

        return num;
    }
}
