import "strconv"

/*
	给定一个正整数和负整数组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

	返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，

	r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

*/
func compressString(S string) string {
	ls := len(S)
	if ls <= 2 {
		return S
	}
	count, res := 1, make([]byte, 0)
	res = append(res, S[0])
	for i := 1; i < ls; i++ {
		if S[i] != S[i-1] {
			res = append(res, []byte(strconv.Itoa(count))...)
			res = append(res, S[i])
			count = 0
		}
		count++
	}
	res = append(res, []byte(strconv.Itoa(count))...)
	if len(res) >= ls {
		return S
	}
	return string(res)
}