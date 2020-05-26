/*
	给定一个整数数组，判断是否存在重复元素。

	如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
*/
func containsDuplicate(nums []int) bool {
	hash := make(map[int]int)
	for _, val := range nums {
		if _, ok := hash[val]; !ok {
			hash[val] = 1
		} else {
			return true
		}
	}
	return false
}