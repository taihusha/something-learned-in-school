/*
 * @lc app=leetcode.cn id=12 lang=golang
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
func intToRoman(num int) string {
	value := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	roman := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	var i int = 0
	var res string = ""
	if num > 3999 || num < 1 {
		return res
	}
	for num >= 0 && i < len(value) {
		if num >= value[i] {
			res += roman[i]
			num -= value[i]
		} else {
			i++
		}
	}
	return res
}

// @lc code=end
