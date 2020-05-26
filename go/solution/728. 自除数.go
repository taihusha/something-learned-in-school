/*
	自除数 是指可以被它包含的每一位数除尽的数。

	例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。

	还有，自除数不允许包含 0 。

	给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

*/
func selfDividingNumbers(left int, right int) []int {
	res := make([]int, 0)
	for i := left; i <= right; i++ {
		num := i
		for num > 0 {
			bit_num := num % 10
			if bit_num != 0 && i%bit_num == 0 {
				num = num / 10
				continue
			} else {
				break
			}
		}
		if num == 0 {
			res = append(res, i)
		}
	}
	return res
}