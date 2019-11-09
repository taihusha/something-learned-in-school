func minWindow(s string, t string) string {
	var res string
	l1, l2 := len(s), len(t)
	map1 := map[rune]int{}
	for _, ch := range t {
		map1[ch]++
	}
	left, max, count := 0, l1+1, l2 //窗口左部分，窗口最大值，消耗t的次数
	for right, ch := range s {
		map1[ch]--
		if map1[ch] >= 0 {
			count--
		}
		for left < right && map1[rune(s[left])] < 0 { //窗口左部分右移
			map1[rune(s[left])]++
			left++
		}
		if count == 0 && max > right-left+1 {
			max = right - left + 1
			res = s[left : right+1]
		}
	}
	return res
}