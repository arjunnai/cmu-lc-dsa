func trap(height []int) int {
    //mlsf = max left so far and mrsf = max right so far
	water, left, right := 0, 0, len(height)-1
    mlsf, mrsf := height[left], height[right]
	for left < right {
		if height[left] < height[right] {
            if height[left]>mlsf{
                mlsf = height[left]
            }else{
                water += mlsf - height[left]
            }
            left++
		}else{
            if height[right]>mrsf{
                mrsf = height[right]
            }else{
                water += mrsf - height[right]
            }
            right-- 
        }
	}
    return water
}