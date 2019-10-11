/*
 * @lc app=leetcode.cn id=42 lang=golang
 *
 * [42] 接雨水
 */

// @lc code=start
func trap(height []int) int {
	var max, maxIndex int
	l := len(height)
	for i, num := range height {
		if num > max {
			max = num
			maxIndex = i
		}
	}
	var leftMax, rightMax, res int
	for i := 0; i < maxIndex; i++ {
		if height[i] > leftMax {
			leftMax = height[i]
		}
		res += leftMax - height[i]
	}
	for i := l - 1; i > maxIndex; i-- {
		if height[i] > rightMax {
			rightMax = height[i]
		}
		res += rightMax - height[i]
	}
	return res
}

// @lc code=end
