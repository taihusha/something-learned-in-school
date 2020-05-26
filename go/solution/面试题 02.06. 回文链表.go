/* 编写一个函数，检查输入的链表是否是回文的。 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 //或可借用数组结构判断是否回文
 //或可利用快慢指针找中点，在过程中将值传入栈中，之后依次比较
 
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	//快慢指针逆转后半部分
	//找到中间结点
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	//翻转后半部分
	tail := reverse(slow)
	//顺序比较值
	for head != nil && tail != nil {
		if head.Val == tail.Val {
			head = head.Next
			tail = tail.Next
		} else {
			return false
		}
	}
	return true
}
func reverse(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}

	cur := head.Next
	head.Next = nil
	for cur != nil {
		next := cur.Next
		cur.Next = head
		head = cur
		cur = next
	}
	return head
}
