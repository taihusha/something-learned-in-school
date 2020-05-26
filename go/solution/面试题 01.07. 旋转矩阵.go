/*
	给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。

	请你设计一种算法，将图像旋转 90 度。

	不占用额外内存空间能否做到？
*/
func rotate(matrix [][]int) {
	//首先对矩阵进行转置
	n, m := len(matrix), len(matrix[0])
	for i := 0; i < n; i++ {
		for j := i + 1; j < m; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
	//然后对矩阵每行进行翻转
	for i := 0; i < n; i++ {
		for s, e := 0, m-1; s < e; {
			matrix[i][s], matrix[i][e] = matrix[i][e], matrix[i][s]
			s++
			e--
		}
	}
}