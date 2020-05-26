/*
	字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。

	给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/
//动态规划，字符串编辑距离
func oneEditAway(first string, second string) bool {
	lf, ls := len(first), len(second)
	if ans(lf-ls) > 1 {
		return false
	}

	//dp[i][j]表示第一个字符到下标i的范围与第二个字符到下标j的范围完全匹配所需的操作次数
	dp := make([][]int, lf+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = make([]int, ls+1)
	}
	for i := 1; i <= lf; i++ {
		dp[i][0] = i
	}
	for j := 1; j <= ls; j++ {
		dp[0][j] = j
	}
	//dp[i][0]=i,删除i个字符，进行i次操作
	//dp[0][j]=j,插入j个字符，进行j次操作

	for i := 0; i < lf; i++ {
		for j := 0; j < ls; j++ {
			if first[i] == second[j] {
				dp[i+1][j+1] = dp[i][j]
			} else {
				dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1
			}
		}
	}
	return dp[lf][ls] <= 1
}
func ans(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func min(a, b, c int) int {
	if a < b && a < c {
		return a
	} else if b < a {
		return b
	}
	return c
}

//模拟过程
func oneEditAway(first string, second string) bool {
	lf, ls := len(first), len(second)
	length := lf - ls
	if length > 1 || length < (-1) {
		return false
	}

	count := 1
	for i, j := 0, 0; i < lf && j < ls; {
		if first[i] != second[j] {
			if length == 1 { //插入
				j--
			} else if length == -1 { //删除
				i--
			}
			count--
		}
		i++
		j++
	}
	return count >= 0
}
