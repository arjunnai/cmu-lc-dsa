func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	finalList := [][]int{}
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue // skip duplicate fixed values
		}
		left, right := i+1, len(nums)-1
		for left < right {
			if nums[i]+nums[left]+nums[right] == 0 {
				finalList = append(finalList, []int{nums[i], nums[left], nums[right]})
				for left < right && nums[left] == nums[left+1] {
					left++
				}
				for left < right && nums[right] == nums[right-1] {
					right--
				}
				left++
				right--

			} else if nums[i]+nums[left]+nums[right] < 0 {
				left++
			} else {
				right--
			}
		}
	}
	return finalList
}