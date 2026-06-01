class Solution {
public:
    string longestDupSubstring(string s) {
        int left = 1, right = s.size() - 1;
        string longestSub = "";

        vector<unsigned long long> pow(s.size(), 1);
        for (int i = 1; i < s.size(); i++) {
            pow[i] = pow[i - 1] * 31;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // string sub = slide_duplicate(s, mid);
            string sub = slide_duplicate(s, mid, pow);
            cout << "mid " << mid << endl << "sub " << sub << endl;
            if (sub == "") {
                right = mid - 1;
            } else {
                left = mid + 1;
                longestSub = sub;
                cout << "updated longestSub to: " << longestSub << endl;
            }
        }
        cout << "returning: " << longestSub << endl;
        return longestSub;
    }
    string slide_duplicate(string s, int L, vector<unsigned long long>& pow) {
        // unordered_set<string> ust;
        unordered_map<unsigned long long, vector<int>> seen;
        unsigned long long curr_hash = 0;

        for (int i = 0; i < L; i++) {
            curr_hash = curr_hash * 31 + (s[i] - 'a' + 1);
        }
        seen[curr_hash].push_back(0);
        for (int right = L; right < s.size(); right++) {
            int left_bound = right - L;
            curr_hash =
                (curr_hash - (s[left_bound] - 'a' + 1) * pow[L - 1]) * 31 +
                (s[right] - 'a' + 1);
            int new_start_idx = left_bound + 1;
            if (seen.contains(curr_hash)) {
                string current_sub = s.substr(new_start_idx, L);
                for (int old_start : seen[curr_hash]) {
                    if (s.compare(old_start, L, current_sub) == 0) {
                        return current_sub;
                    }
                }
                // return s.substr(new_start_idx, L);
            }
            seen[curr_hash].push_back(new_start_idx);
            // string subs = s.substr(right - L, L);
            // if (ust.contains(subs)) {
            //     return subs;
            // }
            // ust.insert(subs);
        }
        return "";
    }
};