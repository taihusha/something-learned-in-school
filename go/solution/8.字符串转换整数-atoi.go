import "math"

/*
 * @lc app=leetcode.cn id=8 lang=golang
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
func myAtoi(str string) int {
	res, minus, length, ix := 0, 1, len(str), 0
	for ix < length && str[ix] == ' ' {
		ix++
	}
	if ix < length {
		if str[ix] == '-' {
			minus = -1
			ix++
		} else if str[ix] == '+' {
			minus = 1
			ix++
		}
	}
	for ix < length && str[ix] >= '0' && str[ix] <= '9' {
		res = res*10 + int(str[ix]) - '0'
		if res*minus > math.MaxInt32 {
			return math.MaxInt32
		} else if res*minus < math.MinInt32 {
			return math.MinInt32
		}
		ix++
	}
	return res * minus

}

// @lc code=end
