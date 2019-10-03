/*
 * @lc app=leetcode.cn id=6 lang=golang
 *
 * [6] Z 字形变换
 */
func convert(s string, numRows int) string {
	var answer string
	var direct string = "down"
	var index int = 0
	result := make([]string, numRows)
	if numRows == 1 {
		return s
	} else {
		for i := 0; i < len(s); i++ {
			result[index] = result[index] + string(s[i])
			if index == numRows-1 {
				direct = "up"
			} else if index == 0 {
				direct = "down"
			}
			if direct == "up" {
				index = index - 1
			} else if direct == "down" {
				index = index + 1
			}
		}
		for i := 0; i < numRows; i++ {
			answer = answer + result[i]
		}
		return answer
	}

}
