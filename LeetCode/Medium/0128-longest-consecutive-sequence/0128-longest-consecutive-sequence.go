func longestConsecutive(nums []int) int {
	//store all elements to hashset - hashset fast lookup
	// loop through all nums in nums
	//check if start of seq i.e. if val-1 exists in nums
	numsSet := make(map[int]struct{})
	maxLength := 0
	for _, val := range nums {
		numsSet[val] = struct{}{}
	}
	for num := range numsSet {
		if _, exists := numsSet[num-1]; exists {
			continue
		} else {
			currLength := 1
			nextNum := num + 1

			for _, exists := numsSet[nextNum]; exists; _, exists = numsSet[nextNum] {
				currLength++
				nextNum++
			}
			if currLength > maxLength {
				maxLength = currLength
			}

		}

	}
	return maxLength
}