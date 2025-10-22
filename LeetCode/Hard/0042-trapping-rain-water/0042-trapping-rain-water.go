func trap(height []int) int {
    //mlsf = max left so far and mrsf = max right so far
	total_water, curr_water, left, right := 0, 0, 0, len(height)-1
    mlsf, mrsf := height[left], height[right]
	for left < right {
		if height[left] < height[right] {
			if mlsf-height[left] < 0 {
				curr_water = 0
			} else {
				curr_water = mlsf - height[left]
			}
            total_water+=curr_water
            if height[left]>mlsf{
                mlsf = height[left]
            }
            left++
		}else{
           	if mrsf-height[right] < 0 {
				curr_water = 0
			} else {
				curr_water = mrsf - height[right]
			}
            total_water+=curr_water
            if height[right]>mrsf{
                mrsf = height[right]
            }
            right-- 
        }
	}
    return total_water
}