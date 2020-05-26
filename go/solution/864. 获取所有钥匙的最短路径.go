/*
	给定一个二维网格 grid。 "." 代表一个空房间， "#" 代表一堵墙， "@" 是起点，（"a", "b", ...）代表钥匙，（"A", "B", ...）代表锁。

	我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。

	我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。

	假设 K 为钥匙/锁的个数，且满足 1 <= K <= 6，字母表中的前 K 个字母在网格中都有自己对应的一个小写和一个大写字母。

	换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。

	返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。

*/
func shortestPathAllKeys(grid []string) int {
	n, m := len(grid), len(grid[0]) //网格大小
	dx := []int{1, -1, 0, 0}
	dy := []int{0, 0, 1, -1} //方向数组
	//找到起点与钥匙个数
	sx, sy, success := 0, 0, 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '@' {
				sx, sy = i, j
			}
			if 'a' <= grid[i][j] && grid[i][j] <= 'f' {
				success |= 1 << uint(grid[i][j]-'a')
			}
		}
	}
	//用一个位掩码来表示a钥匙是否获得
	//标记数组初始化，从不同的路径到达某个钥匙处可能产生不同的key值，这里要添加第三维来记录情况
	visited := make([][][]int, n)
	for i := 0; i < len(visited); i++ {
		visited[i] = make([][]int, m)
		for j := 0; j < m; j++ {
			visited[i][j] = make([]int, success+1)
		}
	}
	visited[sx][sy][0] = 1
	//队列初始化
	queue := make([][]int, 0)
	queue = append(queue, []int{sx, sy, 0, 0})
	//BFS
	for len(queue) > 0 {
		posX, posY, step, key := queue[0][0], queue[0][1], queue[0][2], queue[0][3]
		queue = queue[1:]
		ch := grid[posX][posY]
		if 'a' <= ch && ch <= 'f' {
			key |= 1 << (ch - 'a')
			if key == success {
				return step
			}
		}
		//四个方向的遍历
		for j := 0; j < 4; j++ {
			tempX, tempY := dx[j]+posX, dy[j]+posY
			if tempX < 0 || tempX >= n || tempY < 0 || tempY >= m || visited[tempX][tempY][key] == 1 {
				continue
			}
			ch = grid[tempX][tempY]
			if ch == '#' {
				continue
			}

			if 'A' <= ch && ch <= 'F' {
				temp := ch - 'A'
				if ((key >> temp) & 1) == 0 {
					continue
				}
			}
			visited[tempX][tempY][key] = 1
			queue = append(queue, []int{tempX, tempY, step + 1, key})

		}
	}
	return -1
}