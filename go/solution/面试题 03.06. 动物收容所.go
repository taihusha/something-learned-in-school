/*
	动物收容所。有家动物收容所只收容狗与猫，且严格遵守“先进先出”的原则。

	在收养该收容所的动物时，收养人只能收养所有动物中“最老”（由其进入收容所的时间长短而定）的动物，

	或者可以挑选猫或狗（同时必须收养此类动物中“最老”的）。换言之，收养人不能自由挑选想收养的对象。

	请创建适用于这个系统的数据结构，实现各种操作方法，比如enqueue、dequeueAny、dequeueDog和dequeueCat。

	允许使用Java内置的LinkedList数据结构。

	enqueue方法有一个animal参数，animal[0]代表动物编号，animal[1]代表动物种类，其中 0 代表猫，1 代表狗。

	dequeue*方法返回一个列表[动物编号, 动物种类]，若没有可以收养的动物，则返回[-1,-1]。

*/
type AnimalShelf struct {
	DogQueue []int
	CatQueue []int
}

func Constructor() AnimalShelf {
	return AnimalShelf{
		DogQueue: make([]int, 0),
		CatQueue: make([]int, 0),
	}
}

func (this *AnimalShelf) Enqueue(animal []int) {
	if animal[1] == 0 { //cat
		this.CatQueue = append(this.CatQueue, animal[0])
	} else {
		this.DogQueue = append(this.DogQueue, animal[0])
	}
}

func (this *AnimalShelf) DequeueAny() []int {
	if len(this.DogQueue) == 0 && len(this.CatQueue) == 0 {
		return []int{-1, -1}
	}
	var num, kind int
	if len(this.DogQueue) == 0 {
		num, kind = this.CatQueue[0], 0
		this.CatQueue = this.CatQueue[1:]
	} else if len(this.CatQueue) == 0 {
		num, kind = this.DogQueue[0], 1
		this.DogQueue = this.DogQueue[1:]
	} else if this.CatQueue[0] < this.DogQueue[0] {
		num, kind = this.CatQueue[0], 0
		this.CatQueue = this.CatQueue[1:]
	} else {
		num, kind = this.DogQueue[0], 1
		this.DogQueue = this.DogQueue[1:]
	}
	return []int{num, kind}
}

func (this *AnimalShelf) DequeueDog() []int {
	if len(this.DogQueue) == 0 {
		return []int{-1, -1}
	}
	num, kind := this.DogQueue[0], 1
	this.DogQueue = this.DogQueue[1:]
	return []int{num, kind}
}

func (this *AnimalShelf) DequeueCat() []int {
	if len(this.CatQueue) == 0 {
		return []int{-1, -1}
	}
	num, kind := this.CatQueue[0], 0
	this.CatQueue = this.CatQueue[1:]
	return []int{num, kind}
}

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Enqueue(animal);
 * param_2 := obj.DequeueAny();
 * param_3 := obj.DequeueDog();
 * param_4 := obj.DequeueCat();
 */