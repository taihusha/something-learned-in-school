package controllers

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"lawtest/models"
	"net/http"

	"github.com/astaxie/beego"
)

type LoginController struct {
	beego.Controller
}

var (
	appid  = beego.AppConfig.String("appid")
	secret = beego.AppConfig.String("secret")
)

func (this *LoginController) Get() {

	code := this.GetString("code")

	//获取openid接口
	te_uri := "https://api.weixin.qq.com/sns/jscode2session?appid=" + appid + "&secret=" + secret + "&js_code=" + code + "&grant_type=authorization_code"
	res, _ := http.Get(te_uri)
	body, _ := ioutil.ReadAll(res.Body)
	defer res.Body.Close()

	//json数据的获取与返回
	var userInfo models.WxUser
	json.Unmarshal(body, &userInfo) //反序列化
	fmt.Println(userInfo)
	//新用户注册(无论新老用户尝试一次openid注册)
	models.NewUser(userInfo).Insert()
	this.Data["json"] = userInfo
	this.ServeJSON()
}
