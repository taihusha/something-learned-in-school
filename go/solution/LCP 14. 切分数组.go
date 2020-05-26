/*
	给定一个整数数组 nums ，小李想将 nums 切割成若干个非空子数组，

	使得每个子数组最左边的数和最右边的数的最大公约数大于 1 。

	为了减少他的工作量，请求出最少可以切成多少个子数组。

*/
func splitArray(nums []int) int {
	const inf int = 1e6 + 1
	//找到数组中最大值用于筛质数
	max, res := maxVar(nums), 0
	//埃氏筛，所得数组下标数的内容为其最大质因子
	largestPrime := make([]int, max+5)
	for i := 2; i <= max; i++ {
		if largestPrime[i] == 0 {
			for j := i; j <= max; j += i {
				largestPrime[j] = i
			}
		}
	}
	//dp数组的初始化，给每个元素首先赋一个很大的值
	//dp[p]的含义为质因子为p的某元素位置处在当前范围i内的最小切割数组数
	dp := make([]int, max+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = len(nums) + 1
	}
	//dp[p][i]=min(dp[p][i],f[i-1])
	//f[i]=min(f[i],dp[p][i]+1)
	for i, n := range nums {
		for x := n; x > 1; x /= largestPrime[x] {
			p := largestPrime[x]
			dp[p] = min(dp[p], res)
		}
		res = i + 1
		for x := n; x > 1; x /= largestPrime[x] {
			p := largestPrime[x]
			res = min(res, dp[p]+1)
		}
	}
	return res
}
func maxVar(nums []int) (res int) {
	for _, n := range nums {
		if n > res {
			res = n
		}
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
