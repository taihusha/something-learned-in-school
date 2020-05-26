/*
	在战略游戏中，玩家往往需要发展自己的势力来触发各种新的剧情。

	一个势力的主要属性有三种，分别是文明等级（C），资源储备（R）以及人口数量（H）。在游戏开始时（第 0 天），三种属性的值均为 0。

	随着游戏进程的进行，每一天玩家的三种属性都会对应增加，我们用一个二维数组 increase 来表示每天的增加情况。

	这个二维数组的每个元素是一个长度为 3 的一维数组，例如 [[1,2,1],[3,4,2]] 表示第一天三种属性分别增加 1,2,1 而第二天分别增加 3,4,2。

	所有剧情的触发条件也用一个二维数组 requirements 表示。

	这个二维数组的每个元素是一个长度为 3 的一维数组，对于某个剧情的触发条件 c[i], r[i], h[i]，如果当前 C >= c[i] 且 R >= r[i] 且 H >= h[i] ，则剧情会被触发。

	根据所给信息，请计算每个剧情的触发时间，并以一个数组返回。如果某个剧情不会被触发，则该剧情对应的触发时间为 -1 。

*/
func getTriggerTime(increase [][]int, requirements [][]int) []int {
	res := make([]int, len(requirements))
	for i := 1; i < len(increase); i++ {
		increase[i][0] += increase[i-1][0]
		increase[i][1] += increase[i-1][1]
		increase[i][2] += increase[i-1][2]
	}
	for idx, re := range requirements {
		c, r, h := re[0], re[1], re[2]
		if c+r+h == 0 {
			res[idx] = 0
			continue
		}
		if c > increase[len(increase)-1][0] || r > increase[len(increase)-1][1] || h > increase[len(increase)-1][2] {
			res[idx] = -1
			continue
		}
		begin, end := 0, len(increase)
		mid := begin + (end-begin)/2
		for begin < end {
			if c > increase[mid][0] || r > increase[mid][1] || h > increase[mid][2] {
				begin = mid + 1
			} else {
				if mid == 0 || increase[mid-1][0] < c || increase[mid-1][1] < r || increase[mid-1][2] < h {
					break
				} else {
					end = mid - 1
				}
			}
			mid = begin + (end-begin)/2
		}
		res[idx] = mid + 1
	}
	return res
}