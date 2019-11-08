func maxSubArray(nums []int) int {
	var max, allmax int = 0, nums[0]
	for _, value := range nums {
		if max < 0 {
			max = value
		} else {
			max += value
		}

		if max > allmax {
			allmax = max
		}
	}
	return allmax
}