/*
	反转一个单链表。
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	p := head.Next
	pre := head
	var temp *ListNode
	head.Next = nil
	for p != nil {
		temp = p.Next //获得p的后置结点
		p.Next = pre  //逆转使p的后置结点变为前置
		pre = p       //将pre变为p
		p = temp      //将p变为p的后置结点
	}
	return pre
}