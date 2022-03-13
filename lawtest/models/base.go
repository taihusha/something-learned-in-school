package models

import (
	"time"

	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type BaseModel struct {
	Id        uint `gorm:"primary_key"`
	CreatedAt time.Time
	UpdatedAt time.Time
}

var DB *gorm.DB

func InitDB() (*gorm.DB, error) {
	//user:password@/dbname?charset=utf8&parseTime=True&loc=Local
	db, err := gorm.Open("mysql", "root:123456@/law?charset=utf8&parseTime=True&loc=Local")
	if err == nil {
		DB = db
		//自动迁移，这种方法会忽略外键的产生
		db.AutoMigrate(&User{}, &Page{}, &Practice{}, &Problem{}, &WrongProblem{}, &DifficultProblem{})
		return db, err
	}
	return nil, err
}
