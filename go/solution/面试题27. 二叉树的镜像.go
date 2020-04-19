/*
	请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mirrorTree(root *TreeNode) *TreeNode {
	//根节点不变，左右子树对调
	if root == nil {
		return nil
	}
	temp := root.Right
	root.Right = root.Left
	root.Left = temp
	mirrorTree(root.Right)
	mirrorTree(root.Left)
	return root
}