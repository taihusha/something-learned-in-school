func plusOne(digits []int) []int {
	l, flag := len(digits), 0
	digits[l-1] += 1
	for i := l - 1; i >= 0; i-- {
		if digits[i]+flag > 9 {
			digits[i] = digits[i] + flag - 10
			flag = 1
		} else {
			digits[i] += flag
			flag = 0
		}
	}
	if flag == 1 {
		digits = append([]int{1}, digits...)
	}
	return digits
}