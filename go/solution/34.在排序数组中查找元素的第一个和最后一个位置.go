/*
 * @lc app=leetcode.cn id=34 lang=golang
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
func searchRange(nums []int, target int) []int {
	left := -1
	for i, j := 0, len(nums); i < j; {
		middle := (i + j) / 2
		if nums[middle] == target {
			left = middle
			j = middle
			continue
		}
		if nums[middle] < target {
			i = middle + 1
			continue
		}
		j = middle
	}
	right := -1
	for i, j := 0, len(nums); i < j; {
		middle := (i + j) / 2
		if nums[middle] == target {
			right = middle
			i = middle + 1
			continue
		}
		if nums[middle] < target {
			i = middle + 1
			continue
		}
		j = middle
	}
	return []int{left, right}

}

// @lc code=end
