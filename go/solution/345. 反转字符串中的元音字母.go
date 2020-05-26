/*
	编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
*/
func reverseVowels(s string) string {
	i, j := 0, len(s)-1
	ans := []byte(s)
	for i < j {
		if !isVowel(ans[i]) {
			i++
		}
		if !isVowel(ans[j]) {
			j--
		}
		if isVowel(ans[j]) && isVowel(ans[i]) {
			tmp := ans[j]
			ans[j] = ans[i]
			ans[i] = tmp
			j--
			i++
		}

	}
	S := string(ans)
	return S
}
func isVowel(b byte) bool {
	return b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u' || b == 'A' || b == 'E' || b == 'I' || b == 'O' || b == 'U'
}