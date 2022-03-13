package models

import (
	_ "github.com/jinzhu/gorm/dialects/mysql"
)

type WrongProblem struct {
	BaseModel
	ProblemId uint
	UserId    uint
}

//wrongproblem
func NewWrong() *WrongProblem {
	return &WrongProblem{}
}

func (w *WrongProblem) AddWrong(userid uint, proid uint) error {
	w.ProblemId, w.UserId = proid, userid
	return DB.FirstOrCreate(w, "problem_id = ? and user_id = ?", proid, userid).Error
}

func (w *WrongProblem) DeleteWrong(userid uint, proid uint) error {
	return DB.Where("problem_id = ? and user_id = ?", proid, userid).Delete(w).Error
}

func GetWrong(userid uint) ([]Problem, error) {
	var ps []Problem
	err := DB.Raw("SELECT problems.id,problems.created_at,klp_content,page_id,content,option_a,option_b,option_c,option_d,answer,num,type,scene_content,wrong_problems.updated_at FROM problems,wrong_problems WHERE problems.id=wrong_problems.problem_id AND user_id = ? Order by num ASC", userid).Scan(&ps).Error
	return ps, err
}
