/*
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。

若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。
*/
func findSwapValues(array1 []int, array2 []int) []int {
	// res:=make([]int,2)
	sum1, sum2 := 0, 0
	for _, val := range array1 {
		sum1 += val
	}
	for _, val := range array2 {
		sum2 += val
	}
	sum := sum1 + sum2
	if sum%2 != 0 {
		return nil
	}
	//双循环超时，转用hashmap查找
	target := sum1 - sum/2
	hash := make(map[int]int)
	for i := 0; i < len(array1); i++ {
		hash[array1[i]-target] = array1[i]
	}
	for _, val := range array2 {
		if _, ok := hash[val]; ok {
			return []int{hash[val], val}
		}
	}
	return nil
}