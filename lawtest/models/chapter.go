package models

import (
	"strconv"

	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type Chapter struct {
	Content string `json:"content"`
	Count   int    `json:"count"`
	Type    int    `json:"type"`
}

func GetChapters() ([]Chapter, error) {
	var cs []Chapter
	err := DB.Raw("SELECT type,klp_content as content,COUNT(*) as count FROM problems  GROUP BY klp_content,type").Scan(&cs).Error
	return cs, err
}

func GetCountKlp(content, ty string) ([]Problem, int, error) {
	var (
		count int
		err   error
		ps    []Problem
	)
	t, _ := strconv.Atoi(ty)
	err = DB.Model(&Problem{}).Where("klp_content = ?", content).Count(&count).Error
	if err == nil {
		err = DB.Where("klp_content = ? and type = ?", content, t).Find(&ps).Error
	}
	return ps, count, err
}
