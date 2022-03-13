package models

import (
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type WxUser struct {
	OpenId     string `json:"openid"`
	SessionKey string `json:"session_key"`
}

type User struct {
	BaseModel
	WxUser
	Wrong       []Problem
	Diffculties []Problem
	History     []Practice `gorm:"foreignKey:UserId"`
}

//user
func NewUser(wx WxUser) *User {
	return &User{WxUser: WxUser{OpenId: wx.OpenId, SessionKey: wx.SessionKey}}
}

func (u *User) Insert() error {
	err := DB.FirstOrCreate(u, "open_id = ?", u.OpenId).Error
	return err
}

func GetUserIdByOpenId(openid string) (uint, error) {
	var u User
	err := DB.Select("id").Where("open_id = ?", openid).Find(&u).Error
	return u.Id, err
}
