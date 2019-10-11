/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	flag := 0
	dammnyhead := &ListNode{Next: head}
	node:=dammnyhead
	for node.Next!=nil {
		node=node.Next
		flag++
		
	}
}

// @lc code=end
