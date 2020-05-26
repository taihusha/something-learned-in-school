import "strings"

/*
	力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，

	机器人就会无限循环这条指令的步骤进行移动。指令有两种：


		U: 向y轴正方向移动一格
		R: 向x轴正方向移动一格。


	不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

	给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。
*/
func robot(command string, obstacles [][]int, x int, y int) bool {
	if !isOnThePath(command, x, y) {
		return false
	} else {
		for _, o := range obstacles {
			if x+y > o[0]+o[1] && isOnThePath(command, o[0], o[1]) {
				return false
			}
		}
	}
	return true
}

//求U,R的个数，若x==Rnum,y==Unum，表明在路径上
func isOnThePath(command string, x int, y int) bool {
	uNum := strings.Count(command, "U")*((x+y)/len(command)) + strings.Count(command[0:(x+y)%len(command)], "U")
	rNum := strings.Count(command, "R")*((x+y)/len(command)) + strings.Count(command[0:(x+y)%len(command)], "R")
	if y == uNum && x == rNum {
		return true
	}
	return false
}
