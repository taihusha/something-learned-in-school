/*
	给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。

	求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。
*/
func numSubarrayBoundedMax(A []int, L int, R int) int {
	res, tmp, left := 0, 0, 0
	dp := make([]int, 0)
	for index, val := range A {
		if val > R {
			tmp = 0
			left = index + 1
		} else if val >= L {
			tmp = index - left + 1
			dp = append(dp, tmp)
		} else {
			dp = append(dp, tmp)
		}
	}
	for _, val := range dp {
		res += val
	}
	return res
}