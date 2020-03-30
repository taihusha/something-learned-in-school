/* 
    给定一个二叉树和一个目标和，

    找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

    说明: 叶子节点是指没有子节点的节点。 
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_LEN 1024
int map[MAX_LEN];
int curr;
int count;

void save_res(int** res,int* returnColumnSizes){
    *(returnColumnSizes + count) = curr;
    *(res + count) = (int*)malloc(curr*sizeof(int));
    memcpy(*(res+count),map,curr*sizeof(int));
    ++count;
}

void hasPathSum(struct TreeNode* root, int sum, int** res, int* returnColumnSizes){
    if(root){
        map[curr] = root->val;
        int curr_save = curr;
        ++curr;
        int target = sum - (root->val);
        if(!(root->left)&&!(root->right)){
            if(!target)save_res(res,returnColumnSizes);
            return;
        }
        hasPathSum(root->left,target,res,returnColumnSizes);
        curr = curr_save + 1;
        hasPathSum(root->right,target,res,returnColumnSizes);
        curr = curr_save;
    }
    return;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    int** res = NULL;
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }
    count = 0;
    curr = 0;
    *returnColumnSizes = (int*)malloc(MAX_LEN*sizeof(int));
    res = (int**)malloc(MAX_LEN*sizeof(int*));
    hasPathSum(root,sum,res,*returnColumnSizes);
    *returnSize = count;
    return res;
}