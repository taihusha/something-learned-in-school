//位运算实现
func solveNQueens(n int) [][]string {
	if n == 0 {
		return nil
	}
	res := make([][]int, 0)
	dfs([]int{}, n, 0, 0, 0, &res)
	return generateResult(res, n)
}

func dfs(rows []int, n int, cols, pies, nas int, res *[][]int) {
	//出递归的条件
	row := len(rows)
	if row == n {
		tmp := make([]int, len(rows))
		copy(tmp, rows)
		(*res) = append((*res), tmp)
		return
	}
	ok := (^(cols | pies | nas)) & ((1 << uint(n)) - 1)
	for ok != 0 {
		p := ok & (-ok)
		col := 0
		s := (1 << uint(n-1))
		for p&s == 0 {
			col++
			s >>= 1
		}
		dfs(append(rows, col), n, cols^p, (pies^p)<<1, (nas^p)>>1, res)
		ok ^= p
	}
}

func generateResult(res [][]int, n int) (result [][]string) {
	for _, v := range res {
		var s []string
		for _, val := range v {
			str := ""
			for i := 0; i < n; i++ {
				if i == val {
					str += "Q"
				} else {
					str += "."
				}
			}
			s = append(s, str)
		}
		result = append(result, s)
	}
	return
}
