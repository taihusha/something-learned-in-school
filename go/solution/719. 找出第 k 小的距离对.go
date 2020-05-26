import "sort"

/*
	给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
*/
func smallestDistancePair(nums []int, k int) int {
	sort.Ints(nums)
	l := len(nums)
	low, high := 0, nums[l-1]-nums[0] //距离介于0到最大减最小之间
	for low < high {
		mid := low + (high-low)/2
		count, left := 0, 0
		for right := 1; right < l; right++ {
			for nums[right]-nums[left] > mid {
				left++
			}
			count += right - left
		}
		if count < k {
			low = mid + 1
		} else {
			high = mid
		}
	}
	return low
}