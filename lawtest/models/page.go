package models

import (
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type Page struct {
	BaseModel
	Year     string
	Type     int
	Problems []Problem `gorm:"foreignKey:PageId"`
}

//试卷表的CRUD
func NewPage() *Page {
	return &Page{}
}

func (p *Page) Insert() error {
	return DB.Create(p).Error
}

func (p *Page) Delete() error {
	return DB.Delete(p).Error
}

func GetPage(year string, ty int) (Page, error) {
	var (
		p Page
	)
	err := DB.Preload("Problems", func(db *gorm.DB) *gorm.DB {
		return DB.Order("problems.num ASC")
	}).Find(&p, "year = ? and type = ?", year, ty).Error
	return p, err
}

func GetPages() ([]Page, error) {
	var ps []Page
	err := DB.Order("year DESC").Order("type ASC").Find(&ps).Error
	return ps, err
}
