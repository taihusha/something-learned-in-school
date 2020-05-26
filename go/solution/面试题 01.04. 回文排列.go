/*
	给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

	回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

	回文串不一定是字典当中的单词。
*/
func canPermutePalindrome(s string) bool {
	hash := make(map[rune]int)
	for _, b := range s {
		if _, ok := hash[b]; !ok {
			hash[b] = 1
		} else {
			hash[b]++
		}
	}
	num := 0
	for _, val := range hash {
		if val%2 != 0 {
			num++
		}
	}
	return num <= 1
}