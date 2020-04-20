/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long last;
bool isValidBinarySearchTree(struct TreeNode* root);
bool isValidBST(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	last = LONG_MIN;
	return isValidBinarySearchTree(root);
}
bool isValidBinarySearchTree(struct TreeNode* root){
    if (root==NULL) {
        return true;
    }
    if (isValidBinarySearchTree(root->left)) {
        if (last<root->val) {
            last=root->val;
            return isValidBinarySearchTree(root->right);
        }
    }
    return false;
}