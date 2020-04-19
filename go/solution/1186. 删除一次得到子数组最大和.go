/*
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。

换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），

（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

*/
func maxNum(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
func maximumSum(arr []int) int {
	//dp[i][0]表示不删除时候，到数组下标i的最大值
	//dp[i][1]表示删除时候，到数组下标i的最大值
	if len(arr) == 0 {
		return 0
	}
	dp := make([][2]int, len(arr))
	max := 10 ^ 4
	for i := 0; i < len(arr); i++ {
		if i == 0 {
			dp[i][0] = arr[0]
			dp[i][1] = 0

			max = arr[i]
			continue
		}
		dp[i][0] = maxNum(arr[i], arr[i]+dp[i-1][0])
		dp[i][1] = maxNum(dp[i-1][0], dp[i-1][1]+arr[i])
		if max < maxNum(dp[i][0], dp[i][1]) {
			max = maxNum(dp[i][0], dp[i][1])
		}

	}
	return max
}