/*
   给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。

   返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：


       如果 S[i] == "I"，那么 A[i] < A[i+1]
       如果 S[i] == "D"，那么 A[i] > A[i+1]

*/
func diStringMatch(S string) []int {
	l := len(S)
	min := 0
	max := l
	var i int
	var res = make([]int, l+1)
	for i = 0; i < l; i++ {
		if S[i] == 'I' {
			res[i] = min
			min++
		} else {
			res[i] = max
			max--
		}
	}
	res[i] = min
	return res
}