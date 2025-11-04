func insert(intervals [][]int, newInterval []int) [][]int {
	results := [][]int{}
	nLB, nUB := newInterval[0], newInterval[1]
	i := 0
    //loop before intervals and stop
	for ; i < len(intervals) && intervals[i][1] < nLB; i++ {
		results = append(results, intervals[i])
	}

//merging loop
	for ; i < len(intervals) && intervals[i][0] <= nUB; i++ {
		LB := intervals[i][0]
		UB := intervals[i][1]
		if LB < nLB {
			nLB = LB
		}
		if UB > nUB {
			nUB = UB
		}
	}
	results = append(results, []int{nLB, nUB})

//adding rest of solution to results after merge
	for ; i < len(intervals); i++ {
		results = append(results, intervals[i])
	}

	return results
}
