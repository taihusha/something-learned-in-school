/*
	给定两个用链表表示的整数，每个节点包含一个数位。
	这些数位是反向存放的，也就是个位排在链表首部。
	编写函数对这两个整数求和，并用链表形式返回结果。
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	addMark := 0
	var res = &ListNode{Val: 0}
	cur := res
	for l1 != nil || l2 != nil {
		num1, num2 := 0, 0
		if l1 != nil {
			num1 = l1.Val
		}
		if l2 != nil {
			num2 = l2.Val
		}
		num := num1 + num2 + addMark
		addMark = num / 10
		cur.Next = &ListNode{Val: num % 10}
		cur = cur.Next
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if addMark > 0 {
		cur.Next = &ListNode{Val: addMark}
	}
	return res.Next
}