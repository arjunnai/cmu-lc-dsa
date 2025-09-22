func checkInclusion(s1 string, s2 string) bool {
    freqS1 := make([]int,26)
    freqS2 := make([]int,26)
    w := len(s1)

    if len(s1) > len(s2){
        return false
    }
    for _, ch := range s1{
        idx := int(ch-'a')
        freqS1[idx]++
    }

    for i := 0 ; i < w ; i++{
        idx := int(s2[i] - 'a')
        freqS2[idx]++
    }
        if slices.Equal(freqS1, freqS2) {
            return true
        }
    for i := w; i < len (s2); i++{
        idxOld := int(s2[i-w] - 'a')
        idxNew := int(s2[i] - 'a')
        freqS2[idxOld]--
        freqS2[idxNew]++
        if slices.Equal(freqS1, freqS2) {
            return true
        }
    }
    return false
}