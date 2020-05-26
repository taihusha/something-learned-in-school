/*
	堆盘子。设想有一堆盘子，堆太高可能会倒下来。因此，在现实生活中，盘子堆到一定高度时，我们就会另外堆一堆盘子。

	请实现数据结构SetOfStacks，模拟这种行为。SetOfStacks应该由多个栈组成，并且在前一个栈填满时新建一个栈。

	此外，SetOfStacks.push()和SetOfStacks.pop()应该与普通栈的操作方法相同（也就是说，pop()返回的值，应该跟只有一个栈时的情况一样）。

	进阶：实现一个popAt(int index)方法，根据指定的子栈，执行pop操作。

	当某个栈为空时，应当删除该栈。当栈中没有元素或不存在该栈时，pop，popAt 应返回 -1.

*/
type StackOfPlates struct {
	StackNum int   //栈数量
	Size     int   //栈大小
	Stack    []int //栈本身
	StackLen []int //每个栈的长度
}

func Constructor(cap int) StackOfPlates {
	return StackOfPlates{StackNum: 1, Size: cap, Stack: make([]int, 0), StackLen: make([]int, 1)}
}

func (this *StackOfPlates) Push(val int) {
	if this.Size == 0 { //大小为0 ，不压入数据
		return
	}
	if this.StackNum == 0 || len(this.Stack)/this.StackNum == this.Size {
		this.StackNum++
		this.StackLen = append(this.StackLen, 0)
	}
	this.Stack = append(this.Stack, val)
	this.StackLen[this.StackNum-1]++
}

func (this *StackOfPlates) Pop() int {
	if this.Size > 0 {
		if len(this.Stack) == 0 {
			return -1
		}
		res := this.Stack[len(this.Stack)-1]
		this.Stack = this.Stack[0 : len(this.Stack)-1]
		this.StackLen[this.StackNum-1]--
		if this.StackLen[this.StackNum-1] == 0 { //当前栈大小为0，予以删除
			this.StackNum--
		}
		return res
	}
	return -1
}

func (this *StackOfPlates) PopAt(index int) int {
	if this.Size > 0 {
		if index > this.StackNum-1 {
			return -1
		}
		idx := -1
		for i := 0; i <= index; i++ {
			idx += this.StackLen[i]
		}
		this.StackLen[index]--
		if this.StackLen[index] == 0 { //当前栈大小为0，予以删除
			this.StackLen = append(this.StackLen[:index], this.StackLen[index+1:]...)
			this.StackNum--
		}
		res := this.Stack[idx]
		this.Stack = append(this.Stack[:idx], this.Stack[idx+1:]...) //弹出中间目标元素
		return res
	}
	return -1
}

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * obj := Constructor(cap);
 * obj.Push(val);
 * param_2 := obj.Pop();
 * param_3 := obj.PopAt(index);
 */