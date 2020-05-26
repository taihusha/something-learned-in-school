/*
	编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeDuplicateNodes(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	pre := head
	p := head.Next
	hash := make([]int, 20001)
	hash[head.Val] = 1
	for p != nil {
		if hash[p.Val] == 0 { //第一次出现
			hash[p.Val] = 1
			pre = p
			p = p.Next
		} else if hash[p.Val] == 1 { //重复出现
			pre.Next = p.Next
			p = pre.Next
		}
	}
	return head
}