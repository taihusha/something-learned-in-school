/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */
func lengthOfLongestSubstring(s string) int {
	map1 := map[byte]int{}
	num := 0
	count := 0
	for i, j := 0, 0; i < len(s); i++ {
		if v, ok := map1[s[i]]; v > j-1 && ok { //左窗口边向右滑动
			j = v + 1
		}
		count = i - j + 1
		if num < count {
			num = count
		}
		map1[s[i]] = i
	}
	return num
}
