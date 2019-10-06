/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
func letterCombinations(digits string) []string {
	map1 := map[byte]string{'2': "abc", '3': "def", '4': "ghi", '5': "jkl", '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"}
	var res []string
	for i := 0; i < len(digits); i++ {

		str := map1[digits[i]]
		for j := 0; j < len(str); j++ {
			
			res[i*len(str)+j] = append(res[i*len(str)+j], str[j])
		}

	}
	return res
}

// @lc code=end
