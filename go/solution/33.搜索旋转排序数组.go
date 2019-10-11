/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
func search(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		if nums[left] == target {
			return left
		}
		if nums[right] == target {
			return right
		}
		middle := (left + right) / 2
		if nums[middle] == target {
			return middle
		}
		if nums[left] > nums[right] {
			left += 1
			right -= 1
		} else {
			if nums[middle] > target {
				right = middle - 1
			} else {
				left = middle + 1
			}
		}
	}
	return -1
}

// @lc code=end
