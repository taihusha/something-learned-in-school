/*
	现在, 如果我们最后能走到终点，那么我们的起始节点是最终安全的。

	更具体地说, 存在一个自然数 K,  无论选择从哪里开始行走, 我们走了不到 K 步后必能停止在一个终点。

	哪些节点最终是安全的？ 结果返回一个有序的数组。
*/
// 0表示未访问，
// 1表示已访问成环，
// 2表示已访问不成环
func dfs(graph [][]int, visit []int, pos int) bool {
	if visit[pos] == 1 {
		return false
	}
	if visit[pos] == 2 {
		return true
	}
	if visit[pos] == 0 {
		visit[pos] = 1
		for i := 0; i < len(graph[pos]); i++ {
			if !dfs(graph, visit, graph[pos][i]) {
				return false
			}
		}
		visit[pos] = 2
		return true
	}
	return false
}
func eventualSafeNodes(graph [][]int) []int {
	node_num := len(graph)
	var res []int
	visit := make([]int, node_num)
	for i := 0; i < node_num; i++ { //对每个结点进行深度优先遍历
		if dfs(graph, visit, i) {
			res = append(res, i)
		}
	}
	return res
}