package main

import (
	"fmt"
	"time"
)

type Paint struct {
	Board [][]int
	Boards [][]int
}

var n = 80

func main() {
	Paint := Paint{}
	Paint.Board = createPaint()
	Paint.Boards = createPaint()
	Paint.paintGosperGliderGun()


	//Paint.renderingPaint()
	//
	//Paint.reloadPaint()
	//Paint.Board = Paint.Boards
	//
	//Paint.renderingPaint()
	//return

	for i := 0; i < 1000000000; i++ {
		<-time.Tick(time.Second * 1 / 10)
		fmt.Println(i)
		//cmd := exec.Command("CLS");
		//cmd.Run()
		//cmd2 := exec.Command("PAUSE")
		//cmd2.Run()
		Paint.renderingPaint()

		Paint.reloadPaint()

		Paint.Board = Paint.Boards
		Paint.Boards = createPaint()
	}


}


//创建画布
func createPaint() (board [][]int) {
	//board = make([][]int,n)
	//for i := 0; i < n; i++ {
	//	board[i]= make([]int, n)
	//}
	//return board
	for i := 0; i < n; i++ {
		e := make([]int, n)
		board = append(board, e)
	}
	return board
}

//paint rendering
func (p *Paint)renderingPaint() {
	for i:=0; i<len(p.Board); i++ {
		for ii:=0; ii<len(p.Board[i]); ii++ {
			if p.Board[i][ii] == 1 {
				fmt.Print("#")
			} else {
				fmt.Print(" ")
			}
		}
		fmt.Print("\n")
	}
}

// paint reload
func (p *Paint) reloadPaint() {
	for y:=0; y<len(p.Board); y++ {
		for x:=0; x<len(p.Board[y]); x++ {
			p.reverse(y, x)
		}
	}
}

// reverse 生死判断
func (p *Paint) reverse(y int, x int) {
	var c = 0
	n := n-1
	if y != 0 && x != 0{
		c += p.Board[y-1][x-1]	//左下
	}
	if y != 0 {
		c += p.Board[y-1][x]	//下中
	}
	if x != n && y != 0 {
		c += p.Board[y-1][x+1]	//右下
	}
	if x != 0 {
		c += p.Board[y][x-1]	//左中
	}

	if y != n && x != 0 {
		c += p.Board[y+1][x-1]	//左上
	}
	if y != n && x != n {
		c += p.Board[y+1][x+1]	//右上
	}
	if x != n {
		c += p.Board[y][x+1]	//右中
	}
	if y != n {
		c += p.Board[y+1][x]	//上中
	}

	switch c {
	case 3:
		p.Boards[y][x] = 1
	case 2:
		p.Boards[y][x] = p.Board[y][x]
	default:
		p.Boards[y][x] = 0
	}
}


// paint Gosper Glider Gun 高帕斯滑翔机枪
func (p *Paint) paintGosperGliderGun() {
	n := 20

	p.Board[n+28][n+1] = 1
	p.Board[n+28][n+2] = 1
	p.Board[n+27][n+1] = 1
	p.Board[n+27][n+2] = 1

	p.Board[n+27][n+9] = 1
	p.Board[n+26][n+9] = 1
	p.Board[n+28][n+10] = 1
	p.Board[n+26][n+10] = 1
	p.Board[n+28][n+11] = 1
	p.Board[n+27][n+11] = 1

	p.Board[n+26][n+17] = 1
	p.Board[n+25][n+17] = 1
	p.Board[n+24][n+17] = 1
	p.Board[n+26][n+18] = 1
	p.Board[n+25][n+19] = 1

	p.Board[n+29][n+23] = 1
	p.Board[n+28][n+23] = 1
	p.Board[n+30][n+24] = 1
	p.Board[n+28][n+24] = 1
	p.Board[n+30][n+25] = 1
	p.Board[n+29][n+25] = 1

	p.Board[n+18][n+25] = 1
	p.Board[n+17][n+25] = 1
	p.Board[n+18][n+26] = 1
	p.Board[n+16][n+26] = 1
	p.Board[n+18][n+27] = 1

	p.Board[n+30][n+35] = 1
	p.Board[n+29][n+35] = 1
	p.Board[n+30][n+36] = 1
	p.Board[n+29][n+36] = 1

	p.Board[n+23][n+36] = 1
	p.Board[n+22][n+36] = 1
	p.Board[n+21][n+36] = 1
	p.Board[n+23][n+37] = 1
	p.Board[n+22][n+38] = 1

}


// paint 繁殖者


//


/**
y := 20
	x:= 20
	p.Board[y][x] = 1
	p.Board[y-1][x-1] = 1
	p.Board[y-1][x] = 1
	p.Board[y-1][x+1] = 1
	p.Board[y][x-1] = 1
	p.Board[y+1][x-1] = 1
	p.Board[y+1][x+1] = 1
	p.Board[y][x+1] = 1
	p.Board[y+1][x] = 1
 */


//slic := [][]int{
//	0:{1,1,1,1,1,1,1,1,1,1},
//	1:{1,1,1,1,1,1,1,1,1,1},
//	2:{1,1,1,1,1,1,1,1,1,1},
//	3:{1,1,1,1,1,1,1,1,1,1},
//	4:{1,1,1,1,1,1,1,1,1,1},
//	5:{1,1,1,1,1,1,1,1,1,1},
//	6:{1,1,1,1,1,1,1,1,1,1},
//	7:{1,1,1,1,1,1,1,1,1,1},
//	8:{1,1,1,1,1,1,1,1,1,1},
//	9:{1,1,1,1,1,1,1,1,1,1},
//}
//fmt.Println("slic", slic)
//
//for i:=0; i<len(slic); i++ {
//	for ii:=0; ii<len(slic[i]); ii++ {
//		if slic[i][ii] == 0 {
//			fmt.Print("#")
//		}
//	}
//	fmt.Print("\n")
//
//}