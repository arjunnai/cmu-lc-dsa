import "sort"

func threeSum(nums []int) [][]int {
    var results [][]int
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        
        left := i + 1
        right := len(nums) - 1
        
        for left < right {
            sum := nums[i] + nums[left] + nums[right]
            
            if sum < 0 {
                left++
            } else if sum > 0 {
                right--
            } else {
                resSlice := []int{nums[i], nums[left], nums[right]}
                results = append(results, resSlice)
                left++
                right--
                
                for left < right && nums[left] == nums[left-1] {
                    left++
                }
            }
        }
    }
    
    return results
}