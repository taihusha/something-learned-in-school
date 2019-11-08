func mySqrt(x int) int {
	if x == 0 {
		return 0
	}
	if x <= 3 {
		return 1
	}
	s, e := 0, x
	for s < e {
		m := (s + e) / 2
		if m == s {
			return m
		}
		if m*m == x {
			return m
		} else if m*m < x {
			s = m
		} else if m*m > x {
			e = m
		}
	}
	return 0
}