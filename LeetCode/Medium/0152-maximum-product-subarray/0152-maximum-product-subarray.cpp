class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefProd = 1;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            prefProd *= nums[i];
            maxi = max(prefProd, maxi);
            if (prefProd == 0) {
                prefProd = 1;
            }
        }
        prefProd = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prefProd *= nums[i];
            maxi = max(prefProd, maxi);
            if (prefProd == 0) {
                prefProd = 1;
            }
        }
        return maxi;
    }
};