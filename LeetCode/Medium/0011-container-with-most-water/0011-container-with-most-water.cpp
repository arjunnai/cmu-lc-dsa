class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxArea = 0;
        while (left <= right) {
            maxArea = max(maxArea, ((right - left)*min(height[right], height[left])));
            if (height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};