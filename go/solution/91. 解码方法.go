/*
   一条包含字母 A-Z 的消息通过以下方式进行了编码：

   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26


   给定一个只包含数字的非空字符串，请计算解码方法的总数。

*/
func numDecodings(s string) int {
	n := len(s)
	dp := make([]int, n)
	if s[0] == '0' {
		dp[0] = 0
	} else {
		dp[0] = 1
	}
	for i := 1; i < n; i++ {
		if s[i] != '0' {
			dp[i] = dp[i-1]
		}
		if s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7') {
			if i-2 >= 0 {
				dp[i] += dp[i-2]
			} else {
				dp[i]++
			}
		}
	}
	return dp[n-1]
}