import (
    "container/heap"
)
type MinHeap []int

func (mh MinHeap) Len() int {
    return len(mh)
}

func (mh MinHeap) Less(i, j int) bool {
    return mh[i] < mh[j]
}

func (mh MinHeap) Swap(i, j int) {
    mh[i], mh[j] = mh[j], mh[i]  
}

func (h *MinHeap) Push(x any){
    *h = append(*h , x.(int))
}

func (h *MinHeap) Pop() any{
    itemToReturn := (*h)[len(*h)-1]
    *h = (*h)[:len(*h)-1]
    return itemToReturn
}

type KthLargest struct {
    k    int
    heap *MinHeap
}


func Constructor(k int, nums []int) KthLargest {
	h := &MinHeap{}
	heap.Init(h)
	kl := KthLargest{k: k, heap: h}
    for _, num := range nums {
        kl.Add(num)
    }
    return kl
}


func (this *KthLargest) Add(val int) int {
	if this.heap.Len() < this.k {
		heap.Push(this.heap, val)
	} else if val > (*this.heap)[0] {
		heap.Pop(this.heap)
		heap.Push(this.heap, val)
	}
    return (*this.heap)[0]
}


/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */