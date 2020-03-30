package controller;


import entity.Comment;
import entity.info;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import service.*;
import service.InfoService;
import service.impl.CommentServiceImpl;
import service.impl.InfoServiceImpl;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;


@Controller
public class mainController{
  private InfoService infoService;
  private CommentService commentService;
/*  @RequestMapping(value = "/index")
  public ModelAndView handleRequest(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse) throws Exception {
    ModelAndView mav = new ModelAndView("index");
    infoService = new InfoServiceImpl();
    List<info> infos = infoService.getInfoList(0);
    mav.addObject("list",infos);
    return mav;
  }*/
/*  @RequestMapping("/{id}/detail")
  public String detail(@PathVariable("id") Integer id, Model model) throws SQLException {
    if(id == null){
       return "redirect:/index";
    }
    infoService = new InfoServiceImpl();
    commentService = new CommentServiceImpl();
    info i = infoService.getById(id);
    List<Comment> list = commentService.showComment(id);
    if(i == null){
      return "forward:/index";
    }
    model.addAttribute("info",i);
    model.addAttribute("comment",list);
    return "detail";
  }*/

 //用type指定搜索的种类
  @RequestMapping(value = "/seach")
  public List<info> search(HttpServletRequest req) throws SQLException {
    String text = req.getParameter("search_word");
    System.out.println(text);
    infoService = new InfoServiceImpl();
    List<info> infos = new ArrayList<>();
    //type代表搜索的类型
    infos = infoService.getBySearch(text,Integer.parseInt(req.getParameter("type")));
    return infos;
  }

  @RequestMapping(value = "/addComment")
  public @ResponseBody List<Comment> addComment(HttpServletResponse response,@RequestBody Comment comment ) throws IOException, SQLException {
    commentService = new CommentServiceImpl();
    if(commentService.addComment(comment.getUsername(),comment.getInfoId(),comment.getContent()))
    return commentService.showComment(comment.getInfoId());
    else{
      response.setContentType("text/html; charset=utf-8");
      PrintWriter out = response.getWriter();
      out.print("<script>alert('评论失败');</script>");
     // System.out.println(json.substring(0,json.indexOf("&")));
     // return commentService.showComment(infoId);
    }
    return commentService.showComment(comment.getInfoId());
  }

}