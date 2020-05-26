/* 实现一个MyQueue类，该类用两个栈来实现一个队列。 */
type MyQueue struct {
	Write []int
	Read  []int
}

/** Initialize your data structure here. */
func Constructor() MyQueue {
	return MyQueue{Write: make([]int, 0), Read: make([]int, 0)}
}

/** Push element x to the back of queue. */
func (this *MyQueue) Push(x int) {
	this.Write = append(this.Write, x)
}

/** Removes the element from in front of queue and returns that element. */
func (this *MyQueue) Pop() int {
	for len(this.Write) > 0 {
		num := this.Write[len(this.Write)-1]
		this.Read = append(this.Read, num)
		this.Write = this.Write[:len(this.Write)-1]
	}
	res := this.Read[len(this.Read)-1]
	this.Read = this.Read[:len(this.Read)-1]
	for len(this.Read) > 0 {
		num := this.Read[len(this.Read)-1]
		this.Write = append(this.Write, num)
		this.Read = this.Read[:len(this.Read)-1]
	}
	return res
}

/** Get the front element. */
func (this *MyQueue) Peek() int {
	for len(this.Write) > 0 {
		num := this.Write[len(this.Write)-1]
		this.Read = append(this.Read, num)
		this.Write = this.Write[:len(this.Write)-1]
	}
	res := this.Read[len(this.Read)-1]
	for len(this.Read) > 0 {
		num := this.Read[len(this.Read)-1]
		this.Write = append(this.Write, num)
		this.Read = this.Read[:len(this.Read)-1]
	}
	return res
}

/** Returns whether the queue is empty. */
func (this *MyQueue) Empty() bool {
	return len(this.Write) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */