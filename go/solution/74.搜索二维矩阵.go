func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	for i := 0; i < len(matrix)-1; i++ {
		if target == matrix[i][0] || target == matrix[i+1][0] {
			return true
		} else if target > matrix[i][0] && target < matrix[i+1][0] {
			for j := 0; j < len(matrix[0]); j++ {
				if target == matrix[i][j] {
					return true
				}
			}
		}
	}
	if target == matrix[len(matrix)-1][0] {
		return true
	} else {
		for j := 0; j < len(matrix[0]); j++ {
			if target == matrix[len(matrix)-1][j] {
				return true
			}
		}
	}
	return false
}