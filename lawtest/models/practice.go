package models

import (
	"strconv"

	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type Practice struct {
	BaseModel
	UserId uint
	Origin string
	Grade  int
	Right  []Problem
	Wrong  []Problem
}

//practice
func NewPractice() *Practice {
	return &Practice{}
}

func AddPractice(userid uint, origin string, grade int) error {
	var p Practice = Practice{
		Origin: origin,
		UserId: userid,
	}
	if origin == "tiku" || DB.Where("origin = ? and user_id = ?", origin, userid).Find(&p).RecordNotFound() {
		p.Grade = grade
		return DB.Create(&p).Error
	}
	return DB.Model(&p).Update("grade", grade).Error
}

func (p *Practice) Delete() error {
	return DB.Delete(p).Error
}

func GetGrade(year string, userid uint, ty int) int {
	var p Practice
	origin := year + "_" + strconv.Itoa(ty)
	if DB.Where("origin = ? and user_id = ?", origin, userid).Find(&p).RecordNotFound() {
		return 200
	}
	return p.Grade
}

func GetPractices(userid uint) ([]Practice, error) {
	var ps []Practice
	err := DB.Where("user_id = ?", userid).Find(&ps).Error
	return ps, err
}
