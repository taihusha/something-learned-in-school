package main

import (
	"lawtest/models"
	_ "lawtest/routers"

	"github.com/astaxie/beego"
	"github.com/astaxie/beego/session"
	_ "github.com/astaxie/beego/session/mysql"
	_ "github.com/go-sql-driver/mysql"
)

var globalSessions *session.Manager

func main() {
	db, err := models.InitDB()
	if err != nil {
		panic(err)
	}
	defer db.Close()

	beego.BConfig.WebConfig.Session.SessionOn = true

	//format: username:password@protocol(address)/dbname?param=value
	sessionConfig := &session.ManagerConfig{
		CookieName:      "gosessionid",
		EnableSetCookie: true,
		Gclifetime:      3600,
		Maxlifetime:     3600,
		Secure:          false,
		CookieLifeTime:  3600,
		ProviderConfig:  "root:123456@/lawtest?charset=utf8&parseTime=True&loc=Local",
	}
	globalSessions, _ = session.NewManager("mysql", sessionConfig)
	go globalSessions.GC()
	beego.Run()
}
