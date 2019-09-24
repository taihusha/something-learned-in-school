/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var l *ListNode = &ListNode{} //初始化结构体实例
	pre := l
	flag := 0
	for l1 != nil || l2 != nil {
		pre.Next = &ListNode{} //当前结点
		p := pre.Next
		x := 0
		y := 0
		if l1 == nil {
			x = 0
		} else {
			x = l1.Val
		}
		if l2 == nil {
			y = 0
		} else {
			y = l2.Val
		}
		p.Val = (x + y + flag) % 10
		flag = (x + y + flag) / 10
		pre = p //所得结点指向下一结点
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if flag != 0 {
		pre.Next = &ListNode{Val: flag}
	}
	return l.Next //返回创建结点指向的结点，头结点为空
}
