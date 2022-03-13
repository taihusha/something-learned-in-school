package models

import (
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type DifficultProblem struct {
	BaseModel
	ProblemId uint
	UserId    uint
}

//difficultproblem
func NewDifficult() *DifficultProblem {
	return &DifficultProblem{}
}

func (d *DifficultProblem) GetDifficult(userid uint, problemid uint) bool {
	return DB.Where("problem_id = ? and user_id = ?", problemid, userid).First(d).RecordNotFound()
}

func (d *DifficultProblem) AddDifficult(userid uint, proid uint) error {
	d.ProblemId, d.UserId = proid, userid
	return DB.FirstOrCreate(d, "problem_id = ? and user_id = ?", proid, userid).Error
}

func (d *DifficultProblem) DeleteDifficult(userid uint, proid uint) error {
	return DB.Where("problem_id = ? and user_id = ?", proid, userid).Delete(d).Error
}

func GetDiff(userid uint) ([]Problem, error) {
	var ps []Problem
	err := DB.Raw("SELECT problems.id,problems.created_at,klp_content,page_id,content,option_a,option_b,option_c,option_d,answer,num,type,scene_content,difficult_problems.updated_at FROM problems,difficult_problems WHERE problems.id=difficult_problems.problem_id AND user_id = ? Order by num ASC", userid).Scan(&ps).Error
	return ps, err
}
