package controllers

import (
	"lawtest/models"
	"lawtest/utils"
	"net/url"

	"github.com/astaxie/beego"
)

type KlpController struct {
	beego.Controller
}

//@Title 获得所有章节
//@Description	返回章节数据
//@Success 200 {object} models.KnowledgePoint
//@router /Klp [get]
func (c *KlpController) Get() {
	cs, err := models.GetChapters()
	if err == nil {
		ss := utils.KlpJsonChange(cs)
		c.Data["json"] = ss
		c.ServeJSON()
	}
}

//@Title 获得某个具体章节
//@Description 返回章节内容数据
//@Success 200 {object}
//@router /Klp/:chapter/:type [get]
func (c *KlpController) GetContent() {
	openid := c.GetString("openid")
	userid, err1 := models.GetUserIdByOpenId(openid)
	chapter := c.Ctx.Input.Param(":chapter")
	ty := c.Ctx.Input.Param(":type")
	ch, _ := url.QueryUnescape(chapter)
	ps, _, err2 := models.GetCountKlp(ch, ty)
	if err1 == nil && err2 == nil {
		qs := utils.JsonChange(ps, userid, 1)
		c.Data["json"] = qs
		c.ServeJSON()
	}
}
