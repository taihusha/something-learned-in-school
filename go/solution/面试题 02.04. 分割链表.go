/* 	编写程序以 x 为基准分割链表，使得所有小于 x 的节点排在大于或等于 x 的节点之前。

如果链表中包含 x，x 只需出现在小于 x 的元素之后(如下所示)。

分割元素 x 只需处于“右半部分”即可，其不需要被置于左右两部分之间。

*/
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//头插法
//或可采用尾插法将大于x的元素往后移
//或可使用两个链表结构分别连接比x大的元素和比x小的元素
func partition(head *ListNode, x int) *ListNode {
	pre := head
	node := head
	for node != nil {
		if node.Val < x {
			node.Val, pre.Val = pre.Val, node.Val
			pre = pre.Next
		}
		node = node.Next
	}
	return head
}