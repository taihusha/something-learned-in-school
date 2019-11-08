func minDistance(word1 string, word2 string) int {
	l1, l2 := len(word1), len(word2)
	dp := make([][]int, l1+1)
	for i := 0; i < l1+1; i++ {
		dp[i] = make([]int, l2+1)
		dp[i][0] = i
	}
	for i := 0; i < l2+1; i++ {
		dp[0][i] = i
	}
	right, down, right_down := 0, 0, 0
	for i := 1; i < l1+1; i++ {
		for j := 1; j < l2+1; j++ {
			if word1[i-1] == word2[j-1] {
				right_down = dp[i-1][j-1]
			} else {
				right_down = dp[i-1][j-1] + 1
			}
			right = dp[i][j-1] + 1
			down = dp[i-1][j] + 1
			dp[i][j] = min(right, down, right_down)
		}
	}
	return dp[l1][l2]
}
func min(a int, b int, c int) int {
	if a < b && a < c {
		return a
	} else if b < c && b < a {
		return b
	}
	return c
}