/*
 * @lc app=leetcode.cn id=9 lang=golang
 *
 * [9] 回文数
 */

// @lc code=start
func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	x_copy := x
	var res int
	for x != 0 {
		num := x % 10
		x = x / 10
		res = num + res*10
	}
	return res == x_copy
}

// @lc code=end
