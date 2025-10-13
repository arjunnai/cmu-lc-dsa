func topKFrequent(nums []int, k int) []int {
	freqMap := make(map[int]int)
	for _, val := range nums {
		freqMap[val]++
	}

    freqArr := make([][]int, len(nums)+1)
    for num, freq := range freqMap{
        freqArr[freq] = append(freqArr[freq], num)
    }

    results := []int{}
    for i:=len(freqArr)-1 ; i>=0; i--{
        results = append(results, freqArr[i]...)
        if len(results) == k{
            return results
        }
    }
    return results
}