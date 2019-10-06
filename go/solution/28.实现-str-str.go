/*
 * @lc app=leetcode.cn id=28 lang=golang
 *
 * [28] 实现 strStr()
 */

// @lc code=start
func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}
	length := len(needle)
	for j := 0; j < len(haystack)-length+1; j++ {
		if haystack[j:length+j] == needle {
			return j
		}
	}
	return -1
}

// @lc code=end
