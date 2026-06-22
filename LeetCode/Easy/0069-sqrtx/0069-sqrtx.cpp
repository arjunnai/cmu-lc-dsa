class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        if (x == 1)
            return 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long square = (long long)mid * mid;
            if (square == x) {
                return mid;
            } else if (square < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};