func twoSum(nums []int, target int) []int {
    // Create a map to store numbers we've seen and their index.
    seen := make(map[int]int)

    for i, currentNum := range nums {
        // Calculate the number we need to find to reach the target.
        complement := target - currentNum

        // Check if the complement already exists in our map.
        if j, found := seen[complement]; found {
            // If it exists, we've found our pair of indices!
            return []int{j, i}
        }

        // If not found, add the current number and its index to the map.
        seen[currentNum] = i
    }

    // If we get through the whole loop, no solution exists.
    return nil
}