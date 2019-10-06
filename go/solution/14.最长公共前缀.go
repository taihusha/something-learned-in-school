/*
 * @lc app=leetcode.cn id=14 lang=golang
 *
 * [14] 最长公共前缀
 */

// @lc code=start
func longestCommonPrefix(strs []string) string {
	//strings.HasPrefix(s, prefix string) bool
	if len(strs) == 0 {
		return ""
	}
	ans := len(strs[0])

	for {
		if ans == 0 {
			return ""
		}
		prefix := strs[0][:ans]
		flag := true
		for i := 1; i < len(strs); i++ {
			if len(strs[i]) < ans || strs[i][:ans] != prefix {
				flag = false
				break
			}
		}
		if flag {
			return prefix
		} else {
			ans--
		}
	}
}

// @lc code=end
