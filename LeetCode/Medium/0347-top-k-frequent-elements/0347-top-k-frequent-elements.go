func topKFrequent(nums []int, k int) []int {
	/*
	Count frequencies of all numbers into a hash map.
	Create a buckets array where the index is the frequency.
	Populate the buckets array using your frequency map.
	Get the final answer by iterating through the buckets array.
	if non-empty index, add that to results list, check if len(results) == k
	*/
	freqMap := make(map[int]int)
	for _, val := range nums {
		freqMap[val]++
	}
    arrFreq := make([][]int, len(nums)+1)
    for num, freq := range freqMap {
		arrFreq[freq] = append(arrFreq[freq], num)
	}
    //321
    result := []int{}
    for i := len(arrFreq)-1; i >= 0; i--{
        result = append(result, arrFreq[i]...)
        if len(result) == k{
            return result
        }
    }
    return result
}
