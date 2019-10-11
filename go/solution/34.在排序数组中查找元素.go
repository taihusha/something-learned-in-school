func searchRange(nums []int, target int) []int {
	var left, right int = -1, -1
	s, e := 0, len(nums)
	if e == 0 {
		return []int{left, right}
	}
	if e == 1 && nums[0] == target {
		return []int{0, 0}
	}
	//	le := l - 1
	middle := (s + e) / 2
	if nums[middle] > target && middle != 0 {
		searchRange(nums[s:middle], target)
	} else if nums[middle] < target && middle+1 != e {
		searchRange(nums[middle+1:e], target)
	} else if nums[middle] == target {
		for i := middle; i >= 0; i-- {
			if nums[i] == target {
				left = i
			} else {
				break
			}
		}
		for i := middle; i < e; i++ {
			if nums[i] == target {
				right = i
			} else {
				break
			}

		}
	}
	return []int{left, right}
}