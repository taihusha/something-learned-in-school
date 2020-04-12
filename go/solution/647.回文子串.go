/*
   给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

   具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
*/
func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func countSubstrings(s string) int {
	l := len(s)
	ss := make([]byte, 2*l+3)
	ss[0] = '@'
	ss[1] = '#'
	for t := 0; t < l; t++ {
		ss[t*2+2] = s[t]
		ss[t*2+3] = '#'
	}
	ss[l*2+2] = '!'
	z := make([]int, len(ss))
	center, right := 0, 0
	for i := 1; i < len(ss)-1; i++ {
		if i < right {
			z[i] = min(right-i, z[center*2-i])
		}
		for ss[z[i]+i+1] == ss[i-z[i]-1] {
			z[i]++
		}
		if center+i > right {
			center = i
			right = i + z[i]
		}

	}
	sum := 0
	for _, num := range z {
		sum += (num + 1) / 2
	}
	return sum
}