/*
	请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };



struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root==NULL) {
        return NULL;
    }
    struct TreeNode* temp=root->right;
    root->right=root->left;
    root->left=temp;
    mirrorTree(root->right);
    mirrorTree(root->left);
    return root;
}