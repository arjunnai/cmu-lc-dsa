class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int curr_area = 0, max_area = INT_MIN;

        while (l < r) {
            curr_area = (min(height[l], height[r])) * (r - l);
            max_area = max(max_area, curr_area);
            // cout << "l=" << l << " r=" << r << " h[l]=" << height[l]
            //      << " h[r]=" << height[r] << " curr_area=" << curr_area
            //      << " max_area=" << max_area << endl;
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};