/*
 * @lc app=leetcode.cn id=24 lang=golang
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	/* 	dammnyhead := &ListNode{Next: head}
	   	flag, node1 ,node2:= 0, dammnyhead,head
	   	for node2.Next != nil {
	   		//swap
	   		node1.Next=node2.Next//0->2
	   		node2.Next=node1.Next//2->1
	   		node1.Next=node2.Next.Next//1->3
	   	}
	   	return dammnyhead.Next */
	if head == nil || head.Next == nil {
		return head
	}
	result := head.Next
	head.Next = swapPairs(head.Next.Next)
	result.Next = head
	return result
}

// @lc code=end
