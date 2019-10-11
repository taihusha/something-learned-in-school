/*
 * @lc app=leetcode.cn id=26 lang=golang
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	i, l := 0, len(nums)
	for j := 0; j < l; j++ {
		if j > 0 && nums[j] == nums[j-1] {
			continue
		}
		nums[i] = nums[j]
		i++
	}
	return i
}

// @lc code=end
