func jump(nums []int) int {
	l, res, max, length := len(nums), 0, 0, 0
	if l <= 1 {
		return 0
	}
	for i := 0; i < l; {
		if i+nums[i] >= l-1 {
			return res + 1
		}

		length = 0
		max = 0
		//当前值+下一个值计算最大和
		for j := 1; j <= nums[i] && i+j < l; j++ {
			if j+nums[i+j] >= max {
				max = j + nums[i+j]
				length = j
			}
		}

		i = i + length
		res++
	}

	return res
}