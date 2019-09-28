import (
	"container/list"
	"strconv"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//4ms
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	forward := 0
	resultList := list.List{}
	for l1 != nil && l2 != nil {
		sum := l1.Val + l2.Val + forward
		remain := sum % 10
		forward = sum / 10
		resultList.PushBack(remain)
		l1 = l1.Next
		l2 = l2.Next
	}

	if l1 != nil {
		for l1 != nil {
			sum := l1.Val + forward
			remain := sum % 10
			forward = sum / 10
			resultList.PushBack(remain)
			l1 = l1.Next
		}
	}
	if l2 != nil {
		for l2 != nil {
			sum := l2.Val + forward
			remain := sum % 10
			forward = sum / 10
			resultList.PushBack(remain)
			l2 = l2.Next
		}
	}
	for forward != 0 {
		resultList.PushBack(forward % 10)
		forward = forward / 10
	}
	headNode := &ListNode{}
	tmpNode := headNode
	for node := resultList.Front(); node != nil; node = node.Next() {
		tmpNode.Next = &ListNode{Val: node.Value.(int)}
		tmpNode = tmpNode.Next
	}
	return headNode.Next
}

//12ms，递归
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	first := ListNode{Val: 0}
	doAdd(l1, l2, 0, &first)
	return &first
}

func doAdd(l1 *ListNode, l2 *ListNode, supl int, curNode *ListNode) {
	if l1 == nil {
		l1 = &ListNode{Val: 0}
	}
	if l2 == nil {
		l2 = &ListNode{Val: 0}
	}
	if l1.Next == nil && l2.Next != nil {
		l1.Next = &ListNode{Val: 0}
	}
	if l1.Next != nil && l2.Next == nil {
		l2.Next = &ListNode{Val: 0}
	}
	sum := l1.Val + l2.Val + supl
	if sum >= 10 {
		str := strconv.Itoa(sum)
		var n1 int
		var n2 int
		for index, c := range str {
			v, err := strconv.Atoi(string(c))
			if err == nil {
				if index == 0 {
					n2 = v
				} else {
					n1 = v
				}
			}
		}
		curNode.Val = n1
		nextNode := ListNode{Val: 0}
		curNode.Next = &nextNode
		doAdd(l1.Next, l2.Next, n2, &nextNode)
	} else {
		curNode.Val = sum
		if l1.Next != nil && l2.Next != nil {
			nextNode := ListNode{Val: 0}
			curNode.Next = &nextNode
			doAdd(l1.Next, l2.Next, 0, &nextNode)
		}
	}
}