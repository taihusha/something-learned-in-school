/*
 * @lc app=leetcode.cn id=4 lang=golang
 *
 * [4] 寻找两个有序数组的中位数
 */
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m := len(nums1)
	n := len(nums2)
	if m > n {
		var temp = nums1
		nums1 = nums2
		nums2 = temp
		m = len(nums1)
		n = len(nums2)
	} //确保n≥m
	imin := 0
	imax := m //在[imin,imax] 中进行搜索。
	var i, j int
	for imax >= imin {
		i = (imin + imax) / 2
		j = (m+n+1)/2 - i
		if i < imax && nums2[j-1] > nums1[i] { //i过大，缩小范围
			imin = i + 1
		} else if i > imin && nums1[i-1] > nums2[j] { //i太小，增大范围
			imax = i - 1
		} else {
			maxLeft := 0
			if i == 0 {
				maxLeft = nums2[j-1]
			} else if j == 0 {
				maxLeft = nums1[i-1]
			} else {
				if nums1[i-1] < nums2[j-1] {
					maxLeft = nums2[j-1]
				} else {
					maxLeft = nums1[i-1]
				}
			} //找左边元素中的最大项
			if (m+n)%2 == 1 {
				return (float64)(maxLeft)
			}
			minRight := 0
			if i == m {
				minRight = nums2[j]
			} else if j == n {
				minRight = nums1[i]
			} else {
				if nums1[i] > nums2[j] {
					minRight = nums2[j]
				} else {
					minRight = nums1[i]
				}
			} //找右边元素的最小项
			var res float64 = (float64)(maxLeft+minRight) / 2
			return res
		} //i is perfect
	}
	return 0.0
}
