/* 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func kthToLast(head *ListNode, k int) int {
	quick, slow := head, head
	for k > 0 {
		quick = quick.Next
		k--
	}

	for quick != nil {
		quick = quick.Next
		slow = slow.Next
	}
	return slow.Val
}