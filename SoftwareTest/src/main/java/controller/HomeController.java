package controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import service.impl.HomeService;
import utils.DataOperator;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.util.Map;

/**
 * @author zkw
 * @date 2019/10/31 15:05
 */
@Controller
public class HomeController {

    private HomeService homeService = new HomeService();

    @RequestMapping("/page_login")
    public String page_login(){
        return "login";
    }

    @RequestMapping("/login")
    @ResponseBody
    public Map<String,Object> login(HttpServletRequest req,@RequestParam Map<String, Object> params) throws IOException {
        DataOperator dataOperator = new DataOperator();
        int num = dataOperator.CheckVisitorExists(params);
        if (num == 1) {
            // 账号密码匹配，成功登录
            params.put("result","1");
            homeService.addUserInfo2Session(req,params);
        } else {
            // 账号密码不匹配
            params.put("result","0");
            params.put("message","用户名或密码错误");
        }
        return params;
    }

    @RequestMapping("/page_register")
    public String page_register(){
        return "register";
    }

    @RequestMapping("/register")
    @ResponseBody
    public Map<String,Object> register(HttpServletRequest req,@RequestParam Map<String, Object> params) throws Exception {
        DataOperator dataOperator = new DataOperator();
        int code = dataOperator.AddVisitor(params);
        switch (code){
/*            case 0:     // 账号或密码格式不对
                params.put("result","0");
                params.put("message","用户名由5~10位字母或数字组成，密码由6~10位字母或数字组成，请输入正确的用户名或密码");
                break;*/
            case 2:
                params.put("result","0");
                params.put("message","用户名已被注册！");
                break;
            default:
                params.put("result","1");
                break;
        }

        return params;
    }

    @RequestMapping("/exit")
    public String exit(HttpServletRequest req){
        homeService.deleteUserInfoFromSession(req);
        return "redirect:/";
    }
}
