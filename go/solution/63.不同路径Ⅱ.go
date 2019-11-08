func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if len(obstacleGrid) <= 0 || len(obstacleGrid[0]) <= 0 {
		return 0
	}
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	flag := 0
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		if obstacleGrid[i][0] == 1 {
			flag = 1
		}
		if flag == 1 {
			dp[i][0] = 0

		} else {
			dp[i][0] = 1
		}
	}
	flag = 0
	for i := 0; i < n; i++ {
		if obstacleGrid[0][i] == 1 {
			flag = 1
		}
		if flag == 1 {
			dp[0][i] = 0
		} else {
			dp[0][i] = 1
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 1 {
				dp[i][j] = 0
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[m-1][n-1]
}