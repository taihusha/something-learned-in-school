/*
	给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

	请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。
*/
func numberOfSubstrings(s string) int {
	record := make([]int, 3)
	res := 0
	for left, right := 0, 0; left < len(s) && right < len(s); {
		record[s[right]-'a']++
		for record[0] > 0 && record[1] > 0 && record[2] > 0 {
			res += len(s) - right
			record[s[left]-'a']--
			left++
		}
		right++
	}
	return res
}