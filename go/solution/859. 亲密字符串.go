/*
	给定两个由小写字母构成的字符串 A 和 B ，

	只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，

	就返回 true ；否则返回 false 。
*/
func buddyStrings(A string, B string) bool {
	la, lb := len(A), len(B)
	alphabet := [26]int{}
	if la != lb {
		return false
	}
	nums := make([]int, 2)
	add := 0
	for i := 0; i < la; i++ {
		alphabet[A[i]-'a']++
		if A[i] != B[i] {
			if add == 2 {
				return false
			}
			nums[add] = i
			add++
		}

	}
	for j := 0; j < len(alphabet); j++ {
		if alphabet[j] >= 2 && A == B {
			return true
		}
	}

	if add < 2 {
		return false
	} else {
		if A[nums[0]] == B[nums[1]] && A[nums[1]] == B[nums[0]] {
			return true
		}
	}
	return false
}