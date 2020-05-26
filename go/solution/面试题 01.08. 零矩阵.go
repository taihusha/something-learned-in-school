/*
	编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
*/
func setZeroes(matrix [][]int) {
	n, m := len(matrix), len(matrix[0])
	col, row := make([]int, n), make([]int, m)
	//首先对0所在行列进行标记
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == 0 {
				col[i] = 1
				row[j] = 1
			}
		}
	}
	//然后进行染色
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if col[i] == 1 || row[j] == 1 {
				matrix[i][j] = 0
			}
		}
	}
}