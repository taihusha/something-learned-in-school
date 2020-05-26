/*
	请你设计一个支持下述操作的栈。

	实现自定义栈类 CustomStack ：

		CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
		void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
		int pop()：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1 。
		void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。

*/
type CustomStack struct {
	Stack []int
}

func Constructor(maxSize int) CustomStack {
	return CustomStack{
		Stack: make([]int, 0, maxSize),
	}
}

func (this *CustomStack) Push(x int) {
	if len(this.Stack) == cap(this.Stack) {
		return
	}
	this.Stack = append(this.Stack, x)
}

func (this *CustomStack) Pop() int {
	if len(this.Stack) == 0 {
		return -1
	}
	pop := this.Stack[len(this.Stack)-1]
	this.Stack = this.Stack[:len(this.Stack)-1]
	return pop
}

func (this *CustomStack) Increment(k int, val int) {
	for i := 0; i < k && i < len(this.Stack); i++ {
		this.Stack[i] += val
	}
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */