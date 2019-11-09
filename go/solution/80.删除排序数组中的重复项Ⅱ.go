func removeDuplicates(nums []int) int {
	i, l := 1, len(nums)
	for j := 2; j < l; j++ {
		if nums[i-1] != nums[j] {
			i++
			nums[i] = nums[j]
		}
	}
	return i + 1
}