/*
	实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isBalanced(root.Right) && isBalanced(root.Left) && abs(checkHight(root.Right)-checkHight(root.Left)) <= 1
}
func checkHight(root *TreeNode) int {
	//若返回-1，则不平衡，返回具体值则为高度
	if root != nil {
		return max(checkHight(root.Right), checkHight(root.Left)) + 1
	}
	return 0
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}