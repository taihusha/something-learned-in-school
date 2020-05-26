import (
	"fmt"
	"strings"
)

/*
	给定一个二进制字符串 S（一个仅由若干 '0' 和 '1' 构成的字符串）和一个正整数 N，

	如果对于从 1 到 N 的每个整数 X，其二进制表示都是 S 的子串，就返回 true，否则返回 false。

*/
func queryString(S string, N int) bool {
	for i := 1; i <= N; i++ {
		str := fmt.Sprintf("%b", i)
		if !strings.Contains(S, str) {
			return false
		}
	}
	return true
}