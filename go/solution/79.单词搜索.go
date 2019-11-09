func exist(board [][]byte, word string) bool {
	if len(board) == 0 || len(board[0]) == 0 {
		return false
	}
	m, n := len(board), len(board[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if existTrace(board, word, 0, i, j) {
				return true
			}
		}
	}
	return false
}
func existTrace(board [][]byte, word string, start, i, j int) bool {
	if start == len(word) {
		return true
	}
	if i < 0 || j < 0 || i == len(board) || j == len(board[0]) {
		return false
	}
	if board[i][j] == word[start] {
		start += 1
		board[i][j] ^= byte(128)                    //给当前位置作标记
		if existTrace(board, word, start, i-1, j) { //向上
			return true
		}
		if existTrace(board, word, start, i+1, j) { //向下
			return true
		}
		if existTrace(board, word, start, i, j-1) { //向左
			return true
		}
		if existTrace(board, word, start, i, j+1) { //向右
			return true
		}
		board[i][j] ^= byte(128)
	}
	return false
}