import "math"

/*
 * @lc app=leetcode.cn id=7 lang=golang
 *
 * [7] 整数反转
 */

// @lc code=start
func reverse(x int) int {
	minus := 1
	if x < 0 {
		x = x * -1
		minus = -1
	}
	var res int = 0
	for x != 0 {
		num := x % 10
		x = x / 10
		res = num + res*10
		if res > math.MaxInt32 || res < math.MinInt32 {
			return 0
		}
	}

	return res * minus
}

// @lc code=end
