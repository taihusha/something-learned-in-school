/*
	给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
*/
func sortedSquares(A []int) []int {
	left, right := 0, len(A)-1
	res := make([]int, len(A))
	index := len(A) - 1
	for left <= right {
		nums1 := A[left] * A[left]
		nums2 := A[right] * A[right]
		if nums1 < nums2 {
			res[index] = nums2
			right--
		} else if nums1 >= nums2 {
			res[index] = nums1
			left++
		}
		index--
	}
	return res
}