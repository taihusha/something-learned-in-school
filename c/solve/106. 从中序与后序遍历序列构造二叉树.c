/* 
    根据一棵树的中序遍历与后序遍历构造二叉树。

    注意:
    
    你可以假设树中没有重复的元素。 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findRoot(int* inorder,int s,int e,int target){
    for(int i=s;i<=e;i++){
        if(inorder[i]==target) return i;
    }
    return -1;
}

struct TreeNode* TreeTrace(int* inorder,int si,int ei,int* postorder,int sp,int ep){
    if (si > ei) return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int root_index=findRoot(inorder,si,ei,postorder[ep]);
    node->val=postorder[ep];
    //在下标i之前的为左子树内容，下标i之后的为右子树内容
    node->left=TreeTrace(inorder,si,root_index-1,postorder,sp,sp+root_index-si-1);
    node->right=TreeTrace(inorder,root_index+1,ei,postorder,sp+root_index-si,ep-1);
    return node;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode* root;
    root=TreeTrace(inorder, 0, inorderSize - 1, postorder, 0, postorderSize - 1);
    return root;
}