import (
	"math"
	"sort"
)

/*
 * @lc app=leetcode.cn id=16 lang=golang
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	le := len(nums)
	var res int
	min := math.MaxInt32
	for i := 0; i < le-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		left, right := i+1, le-1
		for left < right {
			if abs(nums[left]+nums[right]+nums[i]-target) < min {
				min = abs(nums[left] + nums[right] + nums[i] - target)
				res = nums[left] + nums[right] + nums[i]
			}
			if nums[left]+nums[right]+nums[i] > target {
				right--
			} else if nums[left]+nums[right]+nums[i] < target {
				left++
			} else {
				return target
			}
		}
	}
	return res
}

func abs(nums int) int {
	if nums < 0 {
		return nums * (-1)
	}
	return nums
}

// @lc code=end
