/*
	现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。

	更具体地说, 存在一个自然数 K,  无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。

	哪些节点最终是安全的？ 结果返回一个有序的数组。
*/ 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 0表示未访问，
// 1表示已访问成环，
// 2表示已访问不成环
bool dfs(int pos, int *visit, int ** graph, int *graphColSize){
    if(visit[pos] == 1) {
        return false; 
    }
    if(visit[pos] == 2) {
        return true; 
    }
    visit[pos] = 1;
    for(int i=0; i<graphColSize[pos]; i++){
        int node = graph[pos][i];
        if(!dfs(node, visit, graph, graphColSize))
            return false;
    }
    visit[pos] = 2;      
    return true;
}
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize){
    int *visit = (int*)malloc(sizeof(int) * graphSize);
    memset(visit, 0, sizeof(int) * graphSize);
    int *res = (int*)malloc(sizeof(int) * graphSize);
    memset(res, 0, sizeof(int) * graphSize);
    *returnSize = 0;
    for(int i=0; i<graphSize; i++){
        if(dfs(i, visit, graph, graphColSize)){
            res[(*returnSize)++] = i;
        }
    }
    return res;
}
