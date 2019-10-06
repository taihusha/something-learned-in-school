/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 */

// @lc code=start
func isValid(s string) bool {
	var stack []byte
	map1 := map[byte]byte{')': '(', ']': '[', '}': '{'}
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
