/*
	在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
*/
func min(a, b, c int) int {
	if a > b {
		if b < c {
			return b
		}
		return c
	} else {
		if a < c {
			return a
		}
		return c
	}
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func maximalSquare(matrix [][]byte) int {
	//dp[i][j]表示到i，j下标的最大边长
	//dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
	col := len(matrix)
	if col == 0 {
		return 0
	}
	row := len(matrix[0])
	res := 0
	dp := make([][]int, col+1)
	for i := 0; i < col+1; i++ {
		dp[i] = make([]int, row+1)
	}
	for i := 1; i <= col; i++ {
		for j := 1; j <= row; j++ {
			if matrix[i-1][j-1] == '1' {
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
				res = max(res, dp[i][j])
			}
		}
	}
	return res * res
}