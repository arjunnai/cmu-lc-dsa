/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bin(MountainArray& mountainArr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }

    int revbin(MountainArray& mountainArr, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target)
                // descending order
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();

        // find peak index
        int l = 0, r = n - 1, peakidx = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
            peakidx = l;
        }

        // 0 -> idx strictly increasing
        int resultidx = bin(mountainArr, 0, peakidx, target);
        if (resultidx != -1)
            return resultidx;
        // idx+1 -> n -> strictly decreasing
        resultidx = revbin(mountainArr, peakidx + 1, n - 1, target);
        return resultidx;
    }
};