/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */
func twoSum(nums []int, target int) []int {
	res := make([]int, 2)
	for i1, value1 := range nums {
		value := target - value1
		res[0] = i1
		for i2 := i1 + 1; i2 < len(nums); i2++ {
			if nums[i2] == value {
				res[1] = i2
				return res
			}
		}
	}
	return nil
}
