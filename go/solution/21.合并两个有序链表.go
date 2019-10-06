/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	dummnyhead := &ListNode{} //哑结点
	/* 	if l1.Val > l2.Val {
	   		dummnyhead.Next = l2
	   	} else {
	   		dummnyhead.Next = l1
	   	} */
	node := dummnyhead
	for l1 != nil || l2 != nil {
		if l1 == nil {
			node.Next = l2
			l2 = nil
			continue
		}
		if l2 == nil {
			node.Next = l1
			l1 = nil
			continue
		}
		if l1.Val > l2.Val {
			node.Next = l2
			l2 = l2.Next
			node = node.Next
		} else {
			node.Next = l1
			l1 = l1.Next
			node = node.Next
		}

	}
	return dummnyhead.Next
}

// @lc code=end
