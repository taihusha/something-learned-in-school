/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/
func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	if n&(n-1) == 0 {
		return true
	}
	return false
}