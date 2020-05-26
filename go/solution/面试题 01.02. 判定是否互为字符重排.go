import (
	"sort"
	"strings"
)

/*
	给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
*/
func CheckPermutation(s1 string, s2 string) bool {
	if len(s1) != len(s2) {
		return false
	}
	tmp1 := strings.Split(s1, "")
	tmp2 := strings.Split(s2, "")

	sort.Strings(tmp1)
	sort.Strings(tmp2)

	res1 := strings.Join(tmp1, "")
	res2 := strings.Join(tmp2, "")
	return res1 == res2
}