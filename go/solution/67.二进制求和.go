func addBinary(a string, b string) string {
	na := len(a)
	nb := len(b)
	ia, ib := na, nb
	result := []byte{}
	// 用来记录是否需要进位
	carry := false
	// 从右往左计算，也就是从个位开始
	for ia > 0 || ib > 0 {
		ia--
		ib--
		// sum用来统计每次的计数和，这里使用int类型
		sum := 0
		if carry {
			sum += 1
			carry = false
		}

		// 判断ab是否还有最高位
		if ia >= 0 {
			sum += int(a[ia] - '0')
		}
		if ib >= 0 {
			sum += int(b[ib] - '0')
		}
		carry = sum > 1
		sum %= 2

		// 计算完毕后将结果加到最左边，也就是最高位
		result = append([]byte{byte(sum + '0')}, result...)

	}

	// 判断是否需要补一个进位1
	if carry {
		result = append([]byte{'1'}, result...)
	}
	return string(result)
}