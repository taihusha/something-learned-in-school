package main

func main() {
	println(longestPalindrome("aabb"))
}
func longestPalindrome(s string) string {
	var mx, id, longest int = 0, 0, 0
	p := make([]int, 2000)
	str := make([]byte, 2*len(s)+2)
	//对字符串预处理
	for i := 0; i < len(s); i++ {
		str[2*i+2] = s[i]
		str[2*i+1] = '#'
	}
	str[0] = '$'
	str[2*len(s)+1] = '#'
	//进行p[i]数组的填充
	for j := 1; j < len(str); j++ {
		if mx > j {
			if 2*id-j > mx-j {
				p[j] = mx - j
			} else {
				p[j] = 2*id - j
			}
		} else {
			p[j] = 1
		}
		for str[j-p[j]] == str[j+p[j]] {
			p[j]++
		}
		if mx < p[j]+j {
			mx = p[j] + j
			id = j
		}
		if mx > longest {
			longest = p[j]
		}
	}
	substr := s[id-longest : id+longest-1]
	return substr
}
