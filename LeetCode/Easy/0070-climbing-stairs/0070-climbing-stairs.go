func climbStairs(n int) int {
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	twoBack := 1
	oneBack := 2
    numWays := 0 
	for i := 3; i < n+1; i++ {
		numWays = twoBack + oneBack
		twoBack = oneBack
		oneBack = numWays
	}

	return numWays
}