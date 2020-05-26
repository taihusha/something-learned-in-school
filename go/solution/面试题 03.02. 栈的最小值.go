/*
	请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。

	执行push、pop和min操作的时间复杂度必须为O(1)。

*/
type MinStack struct {
	Stack [][2]int
	Min   int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	stack := make([][2]int, 0)
	return MinStack{
		Stack: stack,
		Min:   0,
	}
}

func (this *MinStack) Push(x int) {
	if len(this.Stack) == 0 || x < this.Min {
		this.Min = x
	}
	this.Stack = append(this.Stack, [2]int{x, this.Min})

}

func (this *MinStack) Pop() {
	if len(this.Stack) != 1 && this.Stack[len(this.Stack)-1][1] == this.Min {
		this.Min = this.Stack[len(this.Stack)-2][1]
	}
	this.Stack = this.Stack[0 : len(this.Stack)-1]
}

func (this *MinStack) Top() int {
	return this.Stack[len(this.Stack)-1][0]
}

func (this *MinStack) GetMin() int {
	return this.Min
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */