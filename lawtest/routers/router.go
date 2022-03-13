package routers

import (
	"lawtest/controllers"

	"github.com/astaxie/beego"
)

func init() {
	beego.Router("/login", &controllers.LoginController{})
	//注解路由
	beego.Include(&controllers.UserController{})
	beego.Include(&controllers.PageController{})
	beego.Include(&controllers.KlpController{})
	beego.Include(&controllers.PracticeController{})
}

/* //登录验证
var FilterUser = func(ctx *context.Context) {
	_, ok := ctx.Input.Session("uid").(int)
	if !ok && ctx.Request.RequestURI != "/login" {
		ctx.Redirect(302, "/login")
	}
}
*/
