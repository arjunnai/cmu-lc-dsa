class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int waterStored = 0;
        int mlsf = height[l];
        int mrsf = height[r];
            while (l < r) {
            if (mlsf< mrsf) {
                    l++;
                    mlsf = max(mlsf, height[l]);
                    waterStored += mlsf - height[l];
                }
            else {
                r--;
                mrsf = max(mrsf, height[r]);
                waterStored += mrsf - height[r];
            }
        }
        return waterStored;
    }
};