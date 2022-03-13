package controllers

import (
	"lawtest/models"
	"lawtest/utils"

	"github.com/astaxie/beego"
)

type UserController struct {
	beego.Controller
}

//@Title 返回用户难题记录
//@Description	返回用户已保存的难题记录
//@Success 200
//@router /user/getCollecion [get]
func (c *UserController) GetDifficult() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err != nil {
		return
	}
	ps, err := models.GetDiff(userid)
	if err == nil {
		qs := utils.JsonChange(ps, userid, 1)
		c.Data["json"] = qs
		c.ServeJSON()
	}
}

//@Title 返回用户错题记录
//@Description	返回用户已保存的错题记录
//@Success 200
//@router /user/getWrong [get]
func (c *UserController) GetWrong() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err != nil {
		return
	}
	ps, err := models.GetWrong(userid)
	if err == nil {
		qs := utils.JsonChange(ps, userid, 1)
		c.Data["json"] = qs
		c.ServeJSON()
	}
}
