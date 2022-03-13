package controllers

import (
	"lawtest/models"
	"lawtest/utils"
	_ "net/http/pprof"
	"net/url"
	"strconv"

	"github.com/astaxie/beego"
)

type PageController struct {
	beego.Controller
}

//@Title 获得一张试卷
//@Description 返回试卷试题信息
//@Success 200 {object}	models.Page
//@router /page/:year/:type [get]
func (c *PageController) GetPageByYearType() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err != nil {
		return
	}
	var year, ty string
	year = c.Ctx.Input.Param(":year")
	y, _ := url.QueryUnescape(year)
	ty = c.Ctx.Input.Param(":type")
	t, _ := strconv.Atoi(ty)
	p, err := models.GetPage(y, t)
	if err == nil {
		qs := utils.JsonChange(p.Problems, userid, 2)
		c.Data["json"] = qs
		c.ServeJSON()
	}
}

//@Title 获得试卷列表
//@Description 返回所有试卷信息
//@Success 200 {object}	models.Pages
//@router /page [get]
func (c *PageController) GetPages() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	ps, err := models.GetPages()
	if err == nil {
		pps := utils.PageJsonChange(ps, userid)
		c.Data["json"] = pps
		c.ServeJSON()
	}
}
