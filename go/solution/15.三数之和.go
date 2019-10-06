import "sort"

/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	var res [][]int
	sort.Ints(nums)
	le := len(nums)
	for i := 0; i < le-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		if nums[i] > 0 {
			break
		}
		target, left, right := -nums[i], i+1, le-1
		for right > left {
			if nums[left]+nums[right] == target {
				res = append(res, []int{nums[i], nums[left], nums[right]})
				left++
				right--
				for left < right && nums[left] == nums[left-1] {
					left++
				}
				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if nums[left]+nums[right] > target {
				right--
			} else if nums[left]+nums[right] < target {
				left++
			}
		}

	}
	return res
}

// @lc code=end
