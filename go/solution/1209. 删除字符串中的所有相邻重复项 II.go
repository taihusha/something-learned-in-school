/*
给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。
*/
type Stack struct {
	val   rune
	count int
}

func removeDuplicates(s string, k int) string {
	//栈+计数
	stack := make([]Stack, 0, len(s))
	for _, ch := range s {
		if len(stack) == 0 || stack[len(stack)-1].val != ch { //入栈
			stack = append(stack, Stack{
				val:   ch,
				count: 1,
			})
		} else {
			stack[len(stack)-1].count++ //重复元素
		}
		for len(stack) > 0 {
			if stack[len(stack)-1].count == k { //出栈
				stack = stack[:len(stack)-1]
			} else {
				break
			}
		}
	}
	runes := make([]rune, 0, len(s))
	for _, item := range stack {
		for item.count > 0 {
			runes = append(runes, item.val)
			item.count--
		}
	}
	return string(runes)
}
