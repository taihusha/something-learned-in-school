/*
	三合一。描述如何只用一个数组来实现三个栈。

	你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

	构造函数会传入一个stackSize参数，代表每个栈的大小。

*/
type TripleInOne struct {
	Size  int
	Stack []int
}

func Constructor(stackSize int) TripleInOne {
	return TripleInOne{Size: stackSize, Stack: make([]int, 3*stackSize+3)} //前三位分别存放栈的元素个数
}

func (this *TripleInOne) Push(stackNum int, value int) {
	if this.Stack[stackNum] >= this.Size {
		return
	}
	this.Stack[stackNum] += 1
	pos := this.Stack[stackNum]
	this.Stack[stackNum+3*pos] = value
}

func (this *TripleInOne) Pop(stackNum int) int {
	pos := this.Stack[stackNum]
	if pos == 0 {
		return -1
	}
	this.Stack[stackNum] -= 1
	res := this.Stack[pos*3+stackNum]
	return res
}

func (this *TripleInOne) Peek(stackNum int) int {
	pos := this.Stack[stackNum]
	if pos == 0 {
		return -1
	}
	return this.Stack[pos*3+stackNum]
}

func (this *TripleInOne) IsEmpty(stackNum int) bool {
	return this.Stack[stackNum] == 0
}

/**
 * Your TripleInOne object will be instantiated and called as such:
 * obj := Constructor(stackSize);
 * obj.Push(stackNum,value);
 * param_2 := obj.Pop(stackNum);
 * param_3 := obj.Peek(stackNum);
 * param_4 := obj.IsEmpty(stackNum);
 */