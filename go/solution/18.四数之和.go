import "sort"

/*
 * @lc app=leetcode.cn id=18 lang=golang
 *
 * [18] 四数之和
 */

// @lc code=start
func fourSum(nums []int, target int) [][]int {
	l := len(nums)
	sort.Ints(nums)
	var res [][]int
	for i := 0; i < l-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target {
			break
		}
		if nums[i]+nums[l-1]+nums[l-2]+nums[l-3] < target {
			continue
		}
		for j := i + 1; j < l-2; j++ {
			if j != i+1 && nums[j] == nums[j-1] {
				continue
			}
			if nums[j]+nums[j+1]+nums[j+2]+nums[i] > target {
				break
			}
			if nums[j]+nums[i]+nums[l-1]+nums[l-2] < target {
				continue
			}
			targets, left, right := target-nums[i]-nums[j], j+1, l-1
			for left < right {
				if nums[left]+nums[right] == targets {
					res = append(res, []int{nums[i], nums[j], nums[left], nums[right]})
					left++

					for left < right && nums[left] == nums[left-1] {
						left++
					}

				} else if nums[left]+nums[right] < targets {
					left++
				} else if nums[left]+nums[right] > targets {
					right--
				}
			}
		}
	}
	return res
}

// @lc code=end
