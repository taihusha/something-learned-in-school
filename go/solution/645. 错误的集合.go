/*
集合 S 包含从1到 n 的整数。不幸的是，因为数据错误，

导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，

导致集合丢失了一个整数并且有一个元素重复。

给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，

再找到丢失的整数，将它们以数组的形式返回。

*/
func findErrorNums(nums []int) []int {
	hash := make(map[int]int)
	res := make([]int, 2)
	for _, val := range nums {
		if _, ok := hash[val]; ok {
			hash[val]++
			res[0] = val
		} else {
			hash[val] = 1
		}
	}
	for i := 1; i <= len(nums); i++ {
		if _, ok := hash[i]; !ok {
			res[1] = i
			break
		}
	}
	return res
}