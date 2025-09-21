// func containsDuplicate(nums []int) bool {
//     seenAlready := make(map[int]bool)
//     for _, v :=range(nums){
//         if _,ok := seenAlready[v];ok{
//             return true
//         }
//         seenAlready[v]=true
//     }


//     return false
// }

import "sort"

func containsDuplicate(nums []int) bool {
    sort.Ints(nums) // Step 1: Sort the array
    
    // Step 2: Scan for adjacent duplicates
    for i := 0; i < len(nums)-1; i++ {
        if nums[i] == nums[i+1] {
            return true
        }
    }
    
    return false
}