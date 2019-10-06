/*
 * @lc app=leetcode.cn id=11 lang=golang
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
func maxArea(height []int) int {
	left, right, minl, max := 0, len(height)-1, 0, 0
	for left < right {
		if height[left] > height[right] {
			minl = height[right]
		} else {
			minl = height[left]
		}
		if minl*(right-left) > max {
			max = minl * (right - left)
		}
		if height[left] > height[right] {
			right--
		} else {
			left++
		}
	}
	return max
}

// @lc code=end
