class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, count = 0, max = 0;
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            if (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            } else {
                count++;
            }
        }
        return count;
    }
};