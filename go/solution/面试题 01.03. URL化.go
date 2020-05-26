import "strings"

/*
	URL化。编写一种方法，将字符串中的空格全部替换为%20。

	假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。

	（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

*/
//系统API
func replaceSpaces(s string, length int) string {
	return strings.ReplaceAll(s[:length], " ", "%20")
}

//底层实现
func replaceSpaces(S string, length int) string {
	num := 0
	for i := 0; i < length; i++ {
		if S[i] == ' ' {
			num++
		}
	}
	res := make([]byte, num*2+length)
	for i, j := 0, 0; i < length; i++ {
		if S[i] == ' ' {
			res[j] = '%'
			res[j+1] = '2'
			res[j+2] = '0'
			j += 3
		} else {
			res[j] = S[i]
			j += 1
		}
	}
	return string(res)
}