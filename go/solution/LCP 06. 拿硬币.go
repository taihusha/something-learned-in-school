/*
	桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。

	我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。
*/
func minCount(coins []int) int {
	res := 0
	for _, c := range coins {
		res += c/2 + c%2
	}
	return res
}