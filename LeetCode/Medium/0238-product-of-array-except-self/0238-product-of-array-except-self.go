// func productExceptSelf(nums []int) []int {
//     ansArr := make([]int, len(nums))
//     LProduct:=1
//     RProduct:=1

//     for i, v:=range(nums){
        
//         ansArr[i] = LProduct
//         LProduct *= v
//     }

//     for j := len(nums)-1; j>=0; j--{
//         ansArr[j]*=RProduct
//         RProduct*=nums[j]
//     }

//     return ansArr


// }


func productExceptSelf(nums []int) []int {
    n := len(nums)
    ans := make([]int, n)
    ans[0] = 1 // Explicitly set the first element
    
    // Calculate prefix products
    for i := 1; i < n; i++ {
        ans[i] = ans[i-1] * nums[i-1] 
    }
    
    // Calculate suffix products and combine
    for i, R := n-1, 1; i >= 0; i-- { 
        ans[i] = ans[i] * R
        R = R * nums[i]
    }
    return ans
}