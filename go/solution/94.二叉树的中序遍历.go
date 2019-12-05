/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int { //递归
	var res []int
	if root == nil {
		return nil
	}
	tmp1 := inorderTraversal(root.Left)
	res = append(res, tmp1...)

	res = append(res, root.Val)

	tmp2 := inorderTraversal(root.Right)
	res = append(res, tmp2...)

	return res
}
func inorderTraversal(root *TreeNode) []int { //迭代
	if root == nil {
		return nil
	}
	stack, res := []*TreeNode{}, []int{}
	for len(stack) != 0 || root != nil {
		if root != nil {
			stack = append(stack, root)
			root = root.Left
		} else {
			node := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			res = append(res, node.Val)
			root = node.Right
		}
	}
	return res
}
	