func characterReplacement(s string, k int) int {
	//AABABBA
	//map - A{1}
	//countMaxfreq - 1
	//windowLength - 1
	countMaxfreq, maxLength, left := 0, 0, 0
	windowMap := make(map[byte]int)

	for right := 0; right < len(s); right++ {
		windowLength := right - left + 1
		windowMap[s[right]]++
		countMaxfreq = max(countMaxfreq, windowMap[s[right]])
		if (windowLength - countMaxfreq) > k {
			windowMap[s[left]]--
			left++
		} else {
			maxLength = max(maxLength, windowLength)
		}
	}
	return maxLength
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}