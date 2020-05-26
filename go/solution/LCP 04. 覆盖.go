/*
	你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，

	你想把这些骨牌不重叠地覆盖在完好的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。



	输入：n, m代表棋盘的大小；broken是一个b * 2的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。

	输出：一个整数，代表最多能在棋盘上放的骨牌数。
*/

func domino(n int, m int, broken [][]int) int {
	block := make([][]int, n)
	nxt := make([]int, n*m)
	res := 0
	//对数组预处理进行染色
	for i := 0; i < n; i++ {
		block[i] = make([]int, m)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 == 0 {
				block[i][j] = 1
			} else {
				block[i][j] = 2
			}
		}
	}
	//去除障碍
	for _, b := range broken {
		block[b[0]][b[1]] = 0
	}
	//匈牙利算法
	for i := 0; i < len(nxt); i++ {
		nxt[i] = -1
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			used := make([]int, n*m)
			if block[i][j] == 1 && find(i, j, nxt, used, block) {
				res++
			}
		}
	}
	return res

}
func find(i, j int, nxt, used []int, block [][]int) bool {
	n, m := len(block), len(block[0])
	dx := []int{0, 0, 1, -1}
	dy := []int{1, -1, 0, 0}
	pos := i*m + j
	for dir := 0; dir < 4; dir++ {
		nx := i + dx[dir]
		ny := j + dy[dir]
		npos := nx*m + ny

		if nx >= 0 && nx < n && ny >= 0 && ny < m && block[nx][ny] != 0 && used[npos] != 1 {
			used[npos] = 1
			ni := nxt[npos] / m
			nj := nxt[npos] % m
			if nxt[npos] == -1 || find(ni, nj, nxt, used, block) {
				nxt[npos] = pos
				return true
			}
		}
	}
	return false
}