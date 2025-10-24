type Item struct{
    val int
    idx int
}

func dailyTemperatures(temperatures []int) []int {
    //monotonic stack
    stack := list.New()
    result := make ([]int, len(temperatures))

    for i:=0; i< len(temperatures);i++{
        item := &Item{val: temperatures[i], idx : i}
        for stack.Len() != 0{
            top := stack.Back().Value
            topItem := top.(*Item)

            if !(temperatures[i]> topItem.val){
                break
            }
            top = stack.Remove(stack.Back())
            topItem = top.(*Item)
            result[topItem.idx]=i - topItem.idx
        }
        stack.PushBack(item)
    }
    return result
}