import (
	"sort"
	"strings"
)

/*
	实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
*/
//排序后遍历比较
func isUnique(astr string) bool {
	tmp := strings.Split(astr, "")
	sort.Strings(tmp)
	res := strings.Join(tmp, "")
	for i := 1; i < len(res); i++ {
		if res[i] == res[i-1] {
			return false
		}
	}
	return true
}

//64位整型数存储，位运算
func isUnique(astr string) bool {
	var bitSet int64 = 0
	for _, ch := range astr {
		var mask int64 = 1 << (ch - 'A')
		if mask&bitSet != 0 {
			return false
		}
		bitSet |= mask
	}
	return true
}