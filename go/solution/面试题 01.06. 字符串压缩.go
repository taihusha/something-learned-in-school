/*
	字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。

	比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。

	你可以假设字符串中只包含大小写英文字母（a至z）。
*/

import "strconv"

func compressString(S string) string {
	ls := len(S)
	if ls <= 2 {
		return S
	}
	res := make([]byte, 0)
	count := 1
	res = append(res, S[0])
	for i := 1; i < ls; i++ {
		if S[i] == S[i-1] {
			count++
		} else {
			res = append(res, []byte(strconv.Itoa(count))...)
			res = append(res, S[i])
			count = 1
		}
	}
	res = append(res, []byte(strconv.Itoa(count))...)
	if len(res) >= ls {
		return S
	}
	return string(res)
}