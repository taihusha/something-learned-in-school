/*
 * @lc app=leetcode.cn id=41 lang=golang
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); {
		if nums[i] <= len(nums) && nums[i] > 0 && nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		} else {
			i++
		}
	}
	for i, v := range nums {
		if i+1 != v {
			return i + 1
		}
	}
	return len(nums) + 1
}

// @lc code=end
