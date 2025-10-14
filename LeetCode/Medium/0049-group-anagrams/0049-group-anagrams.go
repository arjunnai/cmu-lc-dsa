func groupAnagrams(strs []string) [][]string {
    //empty map that will store final groups
    //loop each word
    //each word - sorted key
    //use key to append original word to list

	freqMap := make(map[string][]string)
	for _, word := range strs {
		runes := []rune(word)
		sort.Slice(runes, func(i, j int) bool {
			return runes[i] < runes[j]
		})
        key := string(runes)
        freqMap[key] = append(freqMap[key], word)
	}
    finalList := make([][]string, 0, len(freqMap))
    for _, anagrams := range freqMap {
    finalList = append(finalList, anagrams)
    }  
    return finalList
}