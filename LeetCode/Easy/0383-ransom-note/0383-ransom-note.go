func canConstruct(ransomNote string, magazine string) bool {
	freqMap := make(map[rune]int)
	for _, char := range magazine {
		if _, ok := freqMap[char]; ok {
			freqMap[char] += 1
		} else {
			freqMap[char] = 1
		}
	}

	for _, char := range ransomNote {
		if count, ok := freqMap[char]; ok && count > 0 {
			freqMap[char] -= 1
		} else {
			return false
		}
	}

	return true
}