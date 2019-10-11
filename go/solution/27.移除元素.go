/*
 * @lc app=leetcode.cn id=27 lang=golang
 *
 * [27] 移除元�
 */

// @lc code=start
func removeElement(nums []int, val int) int {
	var res, l int = 0, len(nums)
	for i := 0; i < l; i++ {
		if nums[i] == val {
			res++
		}
	}
	//flag = res
	for i := 0; i < l-res; i++ {
		if nums[i] == val {
			for j := l - 1; j >= 0; j-- {
				if nums[j] != val {
					temp := nums[j]
					nums[j] = nums[i]
					nums[i] = temp
				}
			}

		}
	}
	return l - res
}

// @lc code=end
