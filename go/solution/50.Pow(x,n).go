func myPow(x float64, n int) float64 {
	var res float64 = 1
	if n < 0 {
		x = 1 / x
		n = 0 - n
	}
	if n == 0 {
		res = 1
	}
	for ; n > 0; n = n >> 1 {
		if n%2 == 1 {
			res *= x
		}
		x *= x
	}
	return res
}
