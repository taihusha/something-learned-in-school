/*
	输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

	B是A的子结构， 即 A中有出现和B相同的结构和节点值。

*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if B == nil || A == nil {
		return false
	}
	return isEqual(A, B) || isSubStructure(A.Right, B) || isSubStructure(A.Left, B)
}
func isEqual(A *TreeNode, B *TreeNode) bool {
	if B == nil {
		return true
	}
	if A == nil {
		return false
	}
	return A.Val == B.Val && isEqual(A.Right, B.Right) && isEqual(A.Left, B.Left)
}
