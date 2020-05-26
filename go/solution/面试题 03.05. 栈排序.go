/*
 	栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。

	最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。

	该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。
*/
type SortedStack struct {
	Stack        []int
	SupportStack []int
}

func Constructor() SortedStack {
	return SortedStack{
		Stack: make([]int, 0), 
		SupportStack: make([]int, 0)
	}
}

func (this *SortedStack) Push(val int) {
	if val <= this.Peek() {
		this.Stack = append(this.Stack, val)
		return
	}
	for len(this.Stack) > 0 && val > this.Peek() {
		num := this.Peek()
		this.SupportStack = append(this.SupportStack, num)
		this.Pop()
	}
	this.Stack = append(this.Stack, val)
	for len(this.SupportStack) > 0 {
		num := this.SupportStack[len(this.SupportStack)-1]
		this.Stack = append(this.Stack, num)
		this.SupportStack = this.SupportStack[:len(this.SupportStack)-1]
	}

}

func (this *SortedStack) Pop() {
	if this.IsEmpty() {
		return
	}
	this.Stack = this.Stack[:len(this.Stack)-1]
}

func (this *SortedStack) Peek() int {
	if this.IsEmpty() {
		return -1
	}
	return this.Stack[len(this.Stack)-1]
}

func (this *SortedStack) IsEmpty() bool {
	return len(this.Stack) == 0
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.IsEmpty();
 */