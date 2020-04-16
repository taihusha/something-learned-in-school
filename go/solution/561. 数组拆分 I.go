import "sort"

/*
	给定长度为 2n 的数组, 你的任务是将这些数分成 n 对,

	例如 (a1, b1), (a2, b2), ..., (an, bn) ，

	使得从1 到 n 的 min(ai, bi) 总和最大。

*/
func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	res := 0
	for i, index := 0, 0; i < len(nums)/2; i++ {
		res += nums[index]
		index += 2
	}
	return res
}