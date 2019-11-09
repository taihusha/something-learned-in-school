func sortColors(nums []int) {
	//三路快排
	i, left, right := 0, -1, len(nums)
	for i < right {
		if nums[i] == 0 {
			nums[left+1], nums[i] = nums[i], nums[left+1]
			left++
			i++
		} else {
			if nums[i] == 2 {
				nums[right-1], nums[i] = nums[i], nums[right-1]
				right--
			} else {
				i++
			}
		}
	}
	return
}