/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。

如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。

所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。

如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。
*/
//并查集
func find(num int, pre []int) int { //返回上级
	for pre[num] != num {
		num = pre[num]
	}
	son := num
	for son != num { //路径压缩
		tmp := pre[son]
		pre[son] = num
		son = tmp
	}
	return num
}

// func makeFriends(num1 int,num2 int,pre []int) {
//     fri1:=find(num1,pre)
//     fri2:=find(num2,pre)
//     if fri1!=fri2 {
//         pre[fri1]=fri2
//     }
//     return
// }
func findCircleNum(M [][]int) int {
	stuNum := len(M)
	res := 0
	pre := make([]int, stuNum)
	for i := 0; i < stuNum; i++ {
		pre[i] = i
	}
	for i := 0; i < stuNum; i++ {
		for j := i + 1; j < stuNum; j++ {
			if M[i][j] == 1 {
				fri1 := find(i, pre)
				fri2 := find(j, pre)
				if fri1 != fri2 {
					pre[fri1] = fri2
					res++
				}
			}
		}
	}
	return stuNum - res
}