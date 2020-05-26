/*
	给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，

	并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

	一般来说，删除节点可分为两个步骤：


		首先找到需要删除的节点；
		如果找到了，删除它。


	说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deleteNode(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return root
	}
	if root.Val < key {
		root.Right = deleteNode(root.Right, key)
	} else if root.Val > key {
		root.Left = deleteNode(root.Left, key)
	} else {
		if root.Right == nil && root.Left == nil {
			return nil
		} else if root.Right != nil {
			root.Val = rightMin(root)
			root.Right = deleteNode(root.Right, root.Val)
		} else {
			root.Val = leftMax(root)
			root.Left = deleteNode(root.Left, root.Val)
		}
	}
	return root
}
func rightMin(root *TreeNode) int {
	root = root.Right
	for root.Left != nil {
		root = root.Left
	}
	return root.Val
}
func leftMax(root *TreeNode) int {
	root = root.Left
	for root.Right != nil {
		root = root.Right
	}
	return root.Val
}