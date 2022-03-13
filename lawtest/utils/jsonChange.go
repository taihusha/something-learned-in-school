package utils

import (
	"lawtest/models"
)

type Question struct {
	ProblemId uint     `json:"problemId"`
	Id        uint     `json:"id`
	Type      string   `json:"type"`
	Answer    string   `json:"a"`
	Content   string   `json:"q"`
	Scene     string   `json:"s"`
	IsWrong   bool     `json:"isWrong"`
	IsStore   bool     `json:"isStore"`
	IsAnswer  int      `json:"isAnswer"`
	Options   []Option `json:"options"`
	Origin    string   `json:"origin"`
	Time      string   `json:"time"`
	Explain   string   `json:"explain"`
}

type Option struct {
	Label   string `json:"label"`
	Text    string `json:"text"`
	Checked bool   `json:"checked"`
}

func JsonChange(ps []models.Problem, userid uint, mode int) []Question {
	var qs []Question
	var typeName string = ""
	var id int
	for idx, p := range ps {
		optiona := Option{
			Label:   "A",
			Text:    p.OptionA,
			Checked: false,
		}
		optionb := Option{
			Label:   "B",
			Text:    p.OptionB,
			Checked: false,
		}
		optionc := Option{
			Label:   "C",
			Text:    p.OptionC,
			Checked: false,
		}
		optiond := Option{
			Label:   "D",
			Text:    p.OptionD,
			Checked: false,
		}
		if p.Type == 1 {
			typeName = "单选"
		} else if p.Type == 2 {
			typeName = "多选"
		} else if p.Type == 3 {
			typeName = "不定项"
		} else if p.Type == 4 {
			typeName = "问答题"
		}
		if mode == 1 {
			id = idx
		} else if mode == 2 {
			id = p.Num - 1
		}
		options := []Option{optiona, optionb, optionc, optiond}
		q := Question{
			ProblemId: p.Id,
			Id:        uint(id),
			Type:      typeName,
			Content:   p.Content,
			Answer:    p.Answer,
			IsWrong:   false,
			IsStore:   false,
			IsAnswer:  0,
			Options:   options,
			Time:      p.UpdatedAt.Format("2006-01-02 15:04"),
			Origin:    models.GetOrigin(p),
		}
		if p.PageId == 0 {
			q.Explain = p.SceneContent
		} else {
			q.Scene = p.SceneContent
		}
		if !models.NewDifficult().GetDifficult(userid, p.Id) {
			q.IsStore = true
		}
		qs = append(qs, q)
	}
	return qs
}

type Section struct {
	Content            string `json:"content"`
	Count              int    `json:"count"`
	RadioCount         int    `json:"radio"`
	MultiCount         int    `json:"multi"`
	IndeterminateCount int    `json:"unsure"`
	IsOpen             bool   `json:"isOpen"`
	Done               []int  `json:"done"`
}

func KlpJsonChange(cs []models.Chapter) []Section {
	var ss []Section
	for i := 4; i < len(cs); i += 3 {
		s := Section{
			Content:            cs[i].Content,
			RadioCount:         cs[i].Count,
			MultiCount:         cs[i+1].Count,
			IndeterminateCount: cs[i+2].Count,
			IsOpen:             false,
			Done:               make([]int, 3),
		}
		s.Count = s.RadioCount + s.MultiCount + s.IndeterminateCount
		ss = append(ss, s)
	}
	return ss
}

type Paper struct {
	Year          string `json:"year"`
	TypeOneGrade  int    `json:"grade1"`
	TypeTwoGrade  int    `json:"grade2"`
	TypThreeGrade int    `json:"grade3"`
	TypeFoutGrade int    `json:"grade4"`
	IsOpen        bool   `json:"isOpen"`
}

func PageJsonChange(ps []models.Page, userid uint) []Paper {
	var pps []Paper
	for i := 0; i < len(ps); i += 4 {
		pp := Paper{
			Year:          ps[i].Year,
			TypeOneGrade:  models.GetGrade(ps[i].Year, userid, ps[i].Type),
			TypeTwoGrade:  models.GetGrade(ps[i+1].Year, userid, ps[i+1].Type),
			TypThreeGrade: models.GetGrade(ps[i+2].Year, userid, ps[i+2].Type),
			TypeFoutGrade: models.GetGrade(ps[i+3].Year, userid, ps[i+3].Type),
			IsOpen:        false,
		}
		pps = append(pps, pp)
	}
	return pps
}
