/*
 * @lc app=leetcode.cn id=19 lang=golang
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head.Next == nil {
		return nil
	}
	dummnyhead := &ListNode{Next: head} //哑结点
	slow, fast := dummnyhead, dummnyhead
	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	for {
		if fast.Next != nil {
			fast = fast.Next
			slow = slow.Next
		} else {
			slow.Next = slow.Next.Next
			break
		}
	}

	return dummnyhead.Next
}

// @lc code=end
