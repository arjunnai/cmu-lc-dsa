func canConstruct(ransomNote string, magazine string) bool {
	// freqMap := make(map[rune]int)
	// for _, char := range magazine {
	// 	if _, ok := freqMap[char]; ok {
	// 		freqMap[char] += 1
	// 	} else {
	// 		freqMap[char] = 1
	// 	}
	// }

	// for _, char := range ransomNote {
	// 	if count, ok := freqMap[char]; ok && count > 0 {
	// 		freqMap[char] -= 1
	// 	} else {
	// 		return false
	// 	}
	// }

	// return true


    freqSlice := make([]int, 26)
    for _, char := range magazine{
        freqSlice[char - 'a'] += 1
    }

    for _, char := range ransomNote{
        if freqSlice[char-'a'] > 0{
            freqSlice[char - 'a'] -= 1
        }else{
            return false
        }
    }
    return true
}