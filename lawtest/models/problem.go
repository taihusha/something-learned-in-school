package models

import (
	"math/rand"
	"strconv"
	"time"

	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type Problem struct {
	BaseModel
	KlpContent   string
	PageId       uint
	Num          int //题目序号
	Type         int
	Content      string //题干
	OptionA      string
	OptionB      string
	OptionC      string
	OptionD      string
	Answer       string
	SceneContent string
}

//题目表的CRUD
func NewProblem() *Problem {
	return &Problem{}
}

func (p *Problem) Insert() error {
	return DB.FirstOrCreate(p, "content = ?", p.Content).Error
}

func (p *Problem) Delete() error {
	return DB.Delete(p).Error
}

func GetProblemById(Id uint) (Problem, error) {
	var p Problem
	err := DB.Find(&p, "id = ?", Id).Error
	return p, err
}

func GetRandomProblem() []Problem {
	var ps []Problem
	rand.Seed(time.Now().Unix())
	num, err := GetProblemNum()
	if err == nil {
		for len(ps) < 10 {
			id := rand.Intn(num) + 1
			p, _ := GetProblemById(uint(id))
			if p.Type == 1 {
				ps = append(ps, p)
			}
		}
		for len(ps) < 15 {
			id := rand.Intn(num) + 1
			p, _ := GetProblemById(uint(id))
			if p.Type == 2 {
				ps = append(ps, p)
			}
		}
		for len(ps) < 20 {
			id := rand.Intn(num) + 1
			p, _ := GetProblemById(uint(id))
			if p.Type == 3 {
				ps = append(ps, p)
			}
		}
	}
	return ps
}

func GetProblemNum() (int, error) {
	var count int
	err := DB.Model(&Problem{}).Count(&count).Error
	return count, err
}

func GetOrigin(p Problem) string {
	if p.PageId != 0 {
		var page Page
		err := DB.Where("id = ?", p.PageId).Find(&page).Error
		if err == nil {
			return page.Year + "试卷" + strconv.Itoa(page.Type)
		}
	}
	if p.KlpContent != "" {
		return p.KlpContent
	}
	return "题库刷题"
}
