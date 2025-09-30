func subsets(nums []int) [][]int {
	res := [][]int{}
	subset := []int{}
	var dfs func(int)
	dfs = func(i int) {
		xI := make([]int, len(subset))
		copy(xI, subset)
		if i >= len(nums) {
			res = append(res, xI)
			return
		}

		//decision to include nums
		subset = append(subset, nums[i])
		dfs(i + 1)
		//decision NOT to include nums
		subset = subset[:len(subset)-1]
		dfs(i + 1)
	}
	dfs(0)
	return res
}