/*
   给定一个排序好的数组，两个整数 k 和 x，

   从数组中找到最靠近 x（两数之差最小）的 k 个数。

   返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。

*/
func findClosestElements(arr []int, k int, x int) []int {
	res := make([]int, k)
	left, right := 0, len(arr)-k
	for left < right {
		mid := (left + right) / 2
		if x-arr[mid] > arr[mid+k]-x {
			left = mid + 1
		} else {
			right = mid
		}
	}
	res = arr[left : left+k]
	return res
}