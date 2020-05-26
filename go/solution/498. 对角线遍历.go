/*
	给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
*/
func findDiagonalOrder(matrix [][]int) []int {

	if len(matrix) == 0 {
		return []int{}
	}
	lr, lc := len(matrix), len(matrix[0])
	res := make([]int, lc*lr)
	col, row := 0, 0
	for i := 0; i < len(res); i++ {
		res[i] = matrix[row][col]
		if (col+row)%2 == 0 {
			if col == lc-1 {
				row++
			} else if row == 0 {
				col++
			} else {
				row--
				col++
			}

		} else {
			if row == lr-1 {
				col++
			} else if col == 0 {
				row++
			} else {
				row++
				col--
			}
		}
	}

	return res
}