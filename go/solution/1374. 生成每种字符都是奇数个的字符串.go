/*
	给你一个整数 n，请你返回一个含 n 个字符的字符串，

	其中每种字符在该字符串中都恰好出现 奇数次 。

	返回的字符串必须只含小写英文字母。如果存在多个满足题目要求的字符串，则返回其中任意一个即可。

*/
func generateTheString(n int) string {
	str := make([]byte, n)
	if n%2 == 1 {
		for i := 0; i < n; i++ {
			str[i] = 'a'
		}
	} else {
		for i := 0; i < n-1; i++ {
			str[i] = 'a'
		}
		str[n-1] = 'b'
	}

	return string(str)
}