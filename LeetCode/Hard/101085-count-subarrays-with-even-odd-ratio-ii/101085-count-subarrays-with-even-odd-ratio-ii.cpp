class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int size = nums.size();
        vector<long long> prefix(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            long long weight = (nums[i] % 2 == 0) ? b : -(long long)a;
            prefix[i + 1] = prefix[i] + weight;
        }

        vector<long long> sortedValues = prefix;
        sort(sortedValues.begin(), sortedValues.end());
        sortedValues.erase(unique(sortedValues.begin(), sortedValues.end()),
                           sortedValues.end());
        int distinctCount = sortedValues.size();

        vector<int> tree(distinctCount + 1, 0);
        auto update = [&](int position) {
            for (; position <= distinctCount;
                 position += position & (-position)) {
                ++tree[position];
            }
        };
        auto query = [&](int position) {
            int total = 0;
            for (; position > 0; position -= position & (-position)) {
                total += tree[position];
            }
            return total;
        };

        long long validCount = 0;
        int inserted = 0;
        for (int j = 0; j <= size; ++j) {
            int rank = int(lower_bound(sortedValues.begin(), sortedValues.end(),
                                       prefix[j]) -
                           sortedValues.begin()) +
                       1;
            validCount += inserted - query(rank - 1);
            update(rank);
            ++inserted;
        }
        return validCount;
    }
};