/*
	找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
*/
func longestSubstring(s string, k int) int {
	if len(s) < k {
		return 0
	}
	table := make([]int, 26)
	for _, ch := range s {
		table[ch-'a']++
	}

	for i := 0; i < len(s); i++ {
		if table[s[i]-'a'] < k {
			left := longestSubstring(s[:i], k)
			for j := i; j < len(s); j++ {
				if table[s[j]-'a'] >= k {
					return max(left, longestSubstring(s[j:], k))
				}
			}
			return left
		}
	}
	return len(s)
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}