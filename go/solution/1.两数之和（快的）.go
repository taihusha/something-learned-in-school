//8ms,使用map
func twoSum(nums []int, target int) []int {
	var ret []int
	var tmpMap = make(map[int]int)
	for k, v := range nums {
		k2, ok := tmpMap[target-v]
		if ok {
			ret = append(ret, k, k2)
			break
		}
		tmpMap[v] = k
	}
	return ret
}

//4ms
func twoSum(nums []int, target int) []int {
	hash := make(map[int]int)
	for i, n := range nums {
		next := target - n
		if _, ok := hash[next]; ok {
			return []int{i, hash[next]}
		} else {
			hash[n] = i
		}
	}
	return []int{0, 0}
}