import "sort"

/*
	设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。
*/
//排序，双指针
func pairSums(nums []int, target int) [][]int {
	var res [][]int
	sort.Ints(nums)
	left, right := 0, len(nums)-1
	for left < right {
		tar := nums[left] + nums[right]
		if tar > target {
			right--
		} else if tar < target {
			left++
		} else {
			res = append(res, []int{nums[left], nums[right]})
			left++
			right--
		}
	}
	return res
}

//hash表辅助存储
func pairSums(nums []int, target int) [][]int {
	var res [][]int
	hash := make(map[int]int)
	for _, val := range nums {
		if hash[target-val] > 0 {
			hash[target-val]--
			res = append(res, []int{val, target - val})
		} else {
			hash[val]++
		}
	}
	return res
}