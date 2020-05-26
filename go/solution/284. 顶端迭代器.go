/*
	给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。

	设计并实现一个支持 peek() 操作的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

*/
/*   Below is the interface for Iterator, which is already defined for you.
 *
 *   type Iterator struct {
 *
 *   }
 *
 *   func (this *Iterator) hasNext() bool {
 *		// Returns true if the iteration has more elements.
 *   }
 *
 *   func (this *Iterator) next() int {
 *		// Returns the next element in the iteration.
 *   }
 */

type PeekingIterator struct {
	Ite     *Iterator
	Cache   int
	isCache bool
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{
		Ite:     iter,
		Cache:   0,
		isCache: false,
	}
}

func (this *PeekingIterator) hasNext() bool {
	return this.isCache || this.Ite.hasNext()
}

func (this *PeekingIterator) next() int {
	if !this.isCache {
		return this.Ite.next()
	}
	res := this.Cache
	this.isCache = false
	return res
}

func (this *PeekingIterator) peek() int {
	if !this.isCache {
		this.Cache = this.Ite.next()
		this.isCache = true
	}

	return this.Cache
}