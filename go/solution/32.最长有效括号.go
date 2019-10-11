/*
 * @lc app=leetcode.cn id=32 lang=golang
 *
 * [32] 最长有效括号
 */

// @lc code=start
func longestValidParentheses(s string) int {
	max, left, right := 0, 0, len(s)
	for i := 0; i < len(s); i++ {
		for j := len(s); j > i; j-- {
			if isValid(s[i:j]) && left-right+1 > max {
				max = left - right + 1
			}
		}
	}
	return max
}
func isValid(s string) bool {
	var stack []byte
	map1 := map[byte]byte{')': '('}
	for _, ch := range s {
		length := len(stack)
		if length > 0 {
			if _, ok := map1[byte(ch)]; ok {
				if stack[length-1] == map1[byte(ch)] {
					stack = stack[:length-1]
					continue
				}
			}
		}
		stack = append(stack, byte(ch))
	}
	return len(stack) == 0
}

// @lc code=end
