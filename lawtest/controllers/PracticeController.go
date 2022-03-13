package controllers

import (
	"fmt"
	"lawtest/models"
	"lawtest/utils"
	"math/rand"

	"strconv"
	"strings"
	"time"

	"github.com/astaxie/beego"
)

type PracticeController struct {
	beego.Controller
}

//@Title 返回某道习题
//@Description	随机生成某个可供练习的习题
//@Success 200 {object} models.Problem
//@router /practice [get]
func (c *PracticeController) Get() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err == nil {
		rand.Seed(time.Now().Unix())
		ps := models.GetRandomProblem()
		qs := utils.JsonChange(ps, userid, 1)
		c.Data["json"] = qs
		c.ServeJSON()
	}
}

//@Title 添加用户做题记录
//@Description 添加用户的做题记录至数据库中
//@Success 200
//@router /addpracice [post]
func (c *PracticeController) AddPractice() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err == nil {
		grade := c.GetString("grade")
		origin := c.GetString("origin")
		g, _ := strconv.Atoi(grade)
		models.AddPractice(userid, origin, g)
	}
}

//@Title 获取用户做题记录
//@Description 得到用户所有的做题记录
//@Success 200
//@router /getpracice [get]
func (c *PracticeController) GetPractice() {

}

//@Title 将习题记录添加至用户记录中
//@Description	返回章节数据
//@Success 200 {object}
//@router /practice/addcollection [post]
func (c *PracticeController) AddColletion() {
	openid := c.GetString("openid")
	userid, err := models.GetUserIdByOpenId(openid)
	if err != nil {
		return
	}
	problem := c.GetString("problems")
	problems := strings.Split(problem, ",")
	for _, pro := range problems {
		proid, _ := strconv.Atoi(pro)
		models.NewDifficult().AddDifficult(userid, uint(proid))
	}
}

//@Title 将习题记录从用户记录中删除
//@Description	删除某条记录
//@Success 200 {object}
//@router /practice/deletecollection [post]
func (c *PracticeController) DeleteCollection() {
	openid := c.GetString("openid")
	problemid := c.GetString("problemid")
	problems := strings.Split(problemid, ",")
	userid, err := models.GetUserIdByOpenId(openid)
	fmt.Println(userid)
	if err == nil {
		for _, pro := range problems {
			proid, _ := strconv.Atoi(pro)
			fmt.Println(proid)
			models.NewDifficult().DeleteDifficult(userid, uint(proid))
		}
	}
}

//@Title 将习题记录添加至用户错题记录中
//@Description	返回章节数据
//@Success 200 {object}
//@router /practice/addwrong [post]
func (c *PracticeController) AddWrong() {
	openid := c.GetString("openid")
	problem := c.GetString("problems")
	problems := strings.Split(problem, ",")
	userid, err := models.GetUserIdByOpenId(openid)
	if err == nil {
		for _, pro := range problems {
			proid, _ := strconv.Atoi(pro)
			models.NewWrong().AddWrong(userid, uint(proid))
		}
	}
}

//@Title 将习题记录从用户错题记录中删除
//@Description	删除某条记录
//@Success 200 {object}
//@router /practice/deletewrong [post]
func (c *PracticeController) DeleteWrong() {
	openid := c.GetString("openid")
	problem := c.GetString("problemid")
	problems := strings.Split(problem, ",")
	userid, err := models.GetUserIdByOpenId(openid)
	if err == nil {
		for _, pro := range problems {
			proid, _ := strconv.Atoi(pro)
			models.NewWrong().DeleteWrong(userid, uint(proid))
		}
	}
}
