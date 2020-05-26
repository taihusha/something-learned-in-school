/*
	给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

	如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

	如果有多种构造方法，请你返回任意一种。
*/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var nums = []int{}

func inorder(treeNode *TreeNode) {
	if treeNode != nil {
		inorder(treeNode.Left)
		nums = append(nums, treeNode.Val)
		inorder(treeNode.Right)
	}
}
func rebuild(start, end int) *TreeNode {
	if start > end {
		return nil
	}
	mid := start + (end-start)/2
	root := &TreeNode{
		Val: nums[mid],
	}
	root.Left = rebuild(start, mid-1)
	root.Val = nums[mid]
	root.Right = rebuild(mid+1, end)
	return root
}
func balanceBST(root *TreeNode) *TreeNode {
	//重组,中序遍历
	nums = make([]int, 0)
	inorder(root)
	length := len(nums)
	return rebuild(0, length-1)
}