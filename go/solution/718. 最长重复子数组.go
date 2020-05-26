/*
	给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度
*/
func findLength(A []int, B []int) int {
	dp := make([][]int, len(A)+1)
	res := 0
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, len(B)+1)
	}
	for i := 0; i < len(A); i++ {
		for j := 0; j < len(B); j++ {
			if A[i] == B[j] {
				dp[i+1][j+1] = dp[i][j] + 1
				res = max(res, dp[i+1][j+1])
			}
		}
	}
	return res
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}