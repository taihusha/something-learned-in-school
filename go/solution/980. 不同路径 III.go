/*
	在二维网格 grid 上，有 4 种类型的方格：
		1 表示起始方格。且只有一个起始方格。
		2 表示结束方格，且只有一个结束方格。
		0 表示我们可以走过的空方格。
		-1 表示我们无法跨越的障碍。
	返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目，每一个无障碍方格都要通过一次。

*/
func uniquePathsIII(grid [][]int) int {
	var sx, sy int
	m, n := len(grid), len(grid[0])
	sum := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 1 {
				sx, sy = i, j
				sum++
			} else if grid[i][j] == 0 {
				sum++
			}
		}
	}

	return dfs(grid, sx, sy, sum)
}
func dfs(grid [][]int, x, y, sum int) int {
	if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) || grid[x][y] == -1 {
		return 0
	}
	if grid[x][y] == 2 && sum == 0 {
		return 1
	} else if grid[x][y] == 2 && sum != 0 {
		return 0
	}
	grid[x][y] = -1
	p1 := dfs(grid, x+1, y, sum-1)
	p2 := dfs(grid, x-1, y, sum-1)
	p3 := dfs(grid, x, y-1, sum-1)
	p4 := dfs(grid, x, y+1, sum-1)
	grid[x][y] = 0
	return p1 + p2 + p3 + p4
}