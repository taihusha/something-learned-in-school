/*
给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。

换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），

（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

*/
#define maxNum(a,b) ((a)>(b))?(a):(b)
int maximumSum(int* arr, int arrSize){
    int dp[arrSize][2];
    if (arrSize == 0) {
		return 0;
	}
    int max= -10 ^ 4;
	for (int i = 0; i < arrSize; i++) {
		if (i == 0){
			dp[i][0] = arr[0];
			dp[i][1] = 0;

			max = arr[i];
			continue;
		}
		dp[i][0] = maxNum(arr[i], arr[i]+dp[i-1][0]);
		dp[i][1] = maxNum(dp[i-1][0], dp[i-1][1]+arr[i]);
		max=maxNum(maxNum(dp[i][0],dp[i][1]),max);
	}
    return max;
}
var currentMaxNode int

func isValidBinarySearchTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	if isValidBinarySearchTree(root.Right) {
		if currentMaxNode > root.Val {
			currentMaxNode = root.Val
			return isValidBinarySearchTree(root.Left)
		}
	}
	return false
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	currentMaxNode = int(^uint(0) >> 1)
	return isValidBinarySearchTree(root)
}
