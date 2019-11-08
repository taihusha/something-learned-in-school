func canJump(nums []int) bool {
	var l, lastPos int = len(nums), len(nums) - 1
	if l == 0 {
		return false
	}
	for i := l - 1; i >= 0; i-- {
		if nums[i]+i >= lastPos {
			lastPos = i
		}
	}
	return i == 0
}