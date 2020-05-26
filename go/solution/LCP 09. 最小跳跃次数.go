/*
	为了给刷题的同学一些奖励，力扣团队引入了一个弹簧游戏机。

	游戏机由 N 个特殊弹簧排成一排，编号为 0 到 N-1。初始有一个小球在编号 0 的弹簧处。若小球在编号为 i 的弹簧处，

	通过按动弹簧，可以选择把小球向右弹射 jump[i] 的距离，或者向左弹射到任意左侧弹簧的位置。

	也就是说，在编号为 i 弹簧处按动弹簧，小球可以弹向 0 到 i-1 中任意弹簧或者 i+jump[i] 的弹簧

	（若 i+jump[i]>=N ，则表示小球弹出了机器）。小球位于编号 0 处的弹簧时不能再向左弹。

	为了获得奖励，你需要将小球弹出机器。请求出最少需要按动多少次弹簧，可以将小球从编号 0 弹簧弹出整个机器，即向右越过编号 N-1 的弹簧。

*/
//小数据可行
var min, far int
var visited []int

func minJump(jump []int) int {
	min = 10 ^ 6
	far = 0
	visited = make([]int, len(jump))
	backtrack(0, 0, jump)
	return min
}
func backtrack(pos, times int, jump []int) {
	if pos+jump[pos] >= len(jump) {
		if times < min {
			min = times + 1
		}
		return
	}
	if visited[pos] != 1 {
		//向右跳

		if visited[pos+jump[pos]] != 1 {
			visited[pos] = 1
			backtrack(pos+jump[pos], times+1, jump)
			visited[pos] = 0
		}

		//向左跳
		for i := pos - 1; i > far; i-- {
			if visited[i] != 1 {
				visited[pos] = 1
				backtrack(i, times+1, jump)
				visited[pos] = 0
			}

		}
	}
	return
}

//优化的广度优先搜索
func minJump(jump []int) int {
	if len(jump) == 0 {
		return 0
	}
	queue := [][]int{}
	queue = append(queue, []int{0, 1})
	visited := make([]int, len(jump))
	visited[0] = 1
	far := 1
	for i := 0; i < len(queue); i++ {
		pos, step := queue[i][0], queue[i][1]
		if pos+jump[pos] >= len(jump) {
			return step
		}
		//向右跳,未访问
		if visited[pos+jump[pos]] == 0 {
			queue = append(queue, []int{pos + jump[pos], step + 1})
			visited[pos+jump[pos]] = step + 1
		}
		//向左跳
		for j := far; j < pos; j++ {
			if visited[j] == 0 {
				queue = append(queue, []int{j, step + 1})
				visited[j] = step + 1
			}
		}
		if far < pos {
			far = pos
		}
	}
	return -1
}
