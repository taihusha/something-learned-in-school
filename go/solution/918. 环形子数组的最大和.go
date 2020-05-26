/*
	给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

	在此处，环形数组意味着数组的末端将会与开头相连呈环状。

	（形式上，当0 <= i < A.length 时 C[i] = A[i]，而当 i >= 0 时 C[i+A.length] = C[i]）

	此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，

	不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）
*/
func Max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func maxSubarraySumCircular(A []int) int {
	//kadane
	max, maxCur := -2<<31, -2<<31
	min, minCur := 2<<31, 2<<31
	maxVal := -2 << 31
	total := 0
	for i := 0; i < len(A); i++ {
		total += A[i]
		maxVal = Max(maxVal, A[i])

		maxCur = Max(A[i], maxCur+A[i])
		max = Max(max, maxCur)

		minCur = Min(A[i], minCur+A[i])
		min = Min(min, minCur)
	}
	if maxVal <= 0 {
		return maxVal
	}

	return Max(max, total-min)
}