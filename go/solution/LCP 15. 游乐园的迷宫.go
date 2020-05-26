/*
	小王来到了游乐园，她玩的第一个项目是模拟推销员。有一个二维平面地图，其中散布着 N 个推销点，编号 0 到 N-1，不存在三点共线的情况。

	每两点之间有一条直线相连。游戏没有规定起点和终点，但限定了每次转角的方向。

	首先，小王需要先选择两个点分别作为起点和终点，然后从起点开始访问剩余 N-2 个点恰好一次并回到终点。

	访问的顺序需要满足一串给定的长度为 N-2 由 L 和 R 组成的字符串 direction，表示从起点出发之后在每个顶点上转角的方向。

	根据这个提示，小王希望你能够帮她找到一个可行的遍历顺序，输出顺序下标（若有多个方案，输出任意一种）。

	可以证明这样的遍历顺序一定是存在的。

*/
func visitOrder(points [][]int, direction string) []int {
	visited := make([]int, len(points))
	res := []int{}
	start, l := 0, len(points)
	//选取最左边的点入列
	for i := 1; i < l; i++ {
		if points[i][0] < points[start][0] {
			start = i
		}
	}
	res = append(res, start)
	visited[start] = 1
	//对方向字符串进行遍历
	for _, dir := range direction {
		next := -1
		if dir == 'L' {
			for j := 0; j < l; j++ { //遍历剩余点，找到相对最右的
				if visited[j] == 0 {
					vector1 := makeVector(points[start], points[j])
					if next == -1 || cross(vector1, makeVector(points[start], points[next])) > 0 {
						next = j
					}
				}
			}
		} else if dir == 'R' { //遍历剩余点，找到相对最左的
			for j := 0; j < l; j++ {
				if visited[j] == 0 {
					vector1 := makeVector(points[start], points[j])
					if next == -1 || cross(vector1, makeVector(points[start], points[next])) < 0 {
						next = j
					}
				}
			}
		}
		res = append(res, next)
		start = next
		visited[next] = 1
	}
	for i := 0; i < l; i++ {
		if visited[i] == 0 {
			res = append(res, i)
			break
		}
	}
	return res
}
func makeVector(point1, point2 []int) []int {
	return []int{point1[0] - point2[0], point1[1] - point2[1]}
}
func cross(vector1, vector2 []int) int {
	return vector1[0]*vector2[1] - vector1[1]*vector2[0]
}