func climbStairs(n int) int {
	//c(n)=c(n-1)+c(n-2)
	//c(1)=1,c(2)=2
	res := make([]int, n)
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	res[0], res[1] = 1, 2
	for i := 2; i < n; i++ {
		res[i] = res[i-1] + res[i-2]
	}
	return res[n-1]
}
func climbStairs(n int) int {
	//c(n)=c(n-1)+c(n-2)
	//c(1)=1,c(2)=2
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	res0, res1 := 1, 2
	for i := 2; i < n; i++ {
		res0, res1 = res1, res0+res1
	}
	return res1
}