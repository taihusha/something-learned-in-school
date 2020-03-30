package controller;

import entity.Comment;
import entity.Scene;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import service.impl.ZkwService;

import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author zkw
 * @date 2019/10/31 13:07
 */
@Controller
public class ZkwController {

    private ZkwService zkwService = new ZkwService();

    @RequestMapping("/index")
    public String index(HttpSession session,Model model, @RequestParam Map<String, Object> params) throws IOException {
        params.put("userId",session.getAttribute("userId"));
        List<Scene> sceneList = zkwService.listSceneInfo(params);

        model.addAttribute("sceneList",sceneList);
        model.addAttribute("search_word",params.get("search_word"));

        return "index";
    }

    @RequestMapping("/praise")
    @ResponseBody
    public Map<String,Object> praise(HttpSession session,Integer sceneId) throws IOException {
        String userId = session.getAttribute("userId").toString();
        Map<String, Object> map = zkwService.praise(userId, sceneId);

        return map;
    }

    @RequestMapping("/{id}/detail")
    public String detail(Model model,@PathVariable("id") Integer id) throws IOException {
        Scene scene = zkwService.getSceneInfoById(id);
        List<Comment> comments = zkwService.getCommentsBySceneId(id);

        model.addAttribute("sceneInfo",scene);
        model.addAttribute("comments",comments);

        return "detail";
    }

    @RequestMapping("/comment")
    @ResponseBody
    public Map<String,Object> comment( @RequestParam Map<String, Object> params) throws IOException {
        int num = zkwService.comment(params);

        params.clear();
        if (num < 1){
            params.put("result","0");
            params.put("message","评论失败");
        }else{
            params.put("result","1");
        }

        return params;
    }
}
