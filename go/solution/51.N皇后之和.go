func solveNQueens(n int) [][]string {
	var res [][]string
	board := printBoard(n)
	backtrack(board, 0, n, &res)
	return res
}
func printBoard(n int) [][]byte {
	res := make([][]byte, n)
	for i := 0; i < n; i++ {
		s := make([]byte, n)
		for j := 0; j < n; j++ {
			s[j] = '.'
		}
		res[i] = s
	}
	return res
}
func backtrack(board [][]byte, row, n int, res *[][]string) {
	if n == row {
		result := make([]string, n)
		for i := 0; i < n; i++ {
			result[i] = string(board[i])
		}
		*res = append(*res, result)
		return
	}

	for i := 0; i < n; i++ { //列的遍历
		//检查同一列是否有放置皇后
		for j := 0; j < n; j++ {
			if board[j][i] == 'Q' {
				goto next
			}
		}
		//检查对角线
		for a, b := row-1, i-1; a >= 0 && b >= 0; {
			if board[a][b] == 'Q' {
				goto next
			}
			a--
			b--
		}
		for a, b := row+1, i-1; a < n && b >= 0; {
			if board[a][b] == 'Q' {
				continue
			}
			a++
			b--
		}
		for a, b := row+1, i+1; a < n && b < n; {
			if board[a][b] == 'Q' {
				goto next
			}
			a++
			b++
		}
		for a, b := row-1, i+1; a >= 0 && b < n; {
			if board[a][b] == 'Q' {
				goto next
			}
			a--
			b++
		}
		board[row][i] = 'Q'
		backtrack(board, row+1, n, res)
		board[row][i] = '.'
	next:
		continue
	}
}
