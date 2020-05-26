/*
	编写一个程序判断给定的数是否为丑数。

	丑数就是只包含质因数 2, 3, 5 的正整数。

*/
func isUgly(num int) bool {
	if num == 0 {
		return false
	}
	for num != 1 {
		if num%5 == 0 {
			num = num / 5
		} else if num%3 == 0 {
			num = num / 3
		} else if num%2 == 0 {
			num = num / 2
		} else {
			return false
		}
	}
	return true
}