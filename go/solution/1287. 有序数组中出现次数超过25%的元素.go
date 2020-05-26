/*
	给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

	请你找到并返回这个整数
*/
func findSpecialInteger(arr []int) int {
	tar := len(arr) / 4
	for i := 0; i < len(arr)-tar; i++ {
		if arr[i] == arr[i+tar] {
			return arr[i]
		}
	}
	return arr[0]
}