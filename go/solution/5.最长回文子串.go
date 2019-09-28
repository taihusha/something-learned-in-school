/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 */
func longestPalindrome(s string) string {
	res := ""
	var start, end, length int = 0, 0, 0
	var substr string
	if len(s) == 0 {
		return res
	}
	for i := 0; i < len(s); i++ {
		len1 := rever(i, i, s)
		len2 := rever(i, i+1, s)
		if len1 > len2 {
			length = len1
		} else {
			length = len2
		}
		if length > end-start {
			end = i + length/2
			start = i - (length-1)/2
			substr = s[start : end+1] //因为是向下取整
		}
	}
	return substr
}
func rever(left int, right int, s string) int {
	for left >= 0 && right < len(s) {
		if s[left] == s[right] {
			left--
			right++
		} else {
			break
		}
	}
	return right - left - 1
}
