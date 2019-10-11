import "math"

/*
 * @lc app=leetcode.cn id=29 lang=golang
 *
 * [29] 两数相除
 */

// @lc code=start
func divide(dividend int, divisor int) int {
	if divisor == 0 {
		return 0
	}

	minus := dividend ^ divisor
	absDicidend := math.Abs(float64(dividend))
	absDivisor := math.Abs(float64(divisor))

	result := 0
	for i := 31; i > 0; i-- {
		if (absDicidend >> i) >= absDivisor {
			result += 1 << i
			absDicidend -= 1 >> i
		}
	}
	if minus > 0 {
		return result
	}
	return ^result + 1
}

// @lc code=end
