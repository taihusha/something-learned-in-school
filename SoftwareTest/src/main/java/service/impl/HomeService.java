package service.impl;

import entity.Visitor;
import factory.SessionFactorySingleton;
import mapper.BaseMapper;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.springframework.stereotype.Service;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.Map;

/**
 * @author zkw
 * @date 2019/10/31 15:07
 */
@Service
public class HomeService {


    public void addUserInfo2Session(HttpServletRequest req, Map<String, Object> params) throws IOException {
        Visitor visitor = null;
        HttpSession session = req.getSession();
        SqlSessionFactory sessionFactory = SessionFactorySingleton.getSessionFactory();
        try( SqlSession sqlSession = sessionFactory.openSession(true)){
            BaseMapper mapper = sqlSession.getMapper(BaseMapper.class);
            visitor = mapper.getUserInfo(params);
        }

        session.setAttribute("userId",visitor.getId());
        session.setAttribute("username",visitor.getUsername());
    }

    public void deleteUserInfoFromSession(HttpServletRequest req) {
        HttpSession session = req.getSession();
        session.removeAttribute("username");
        session.removeAttribute("userId");
    }
}
