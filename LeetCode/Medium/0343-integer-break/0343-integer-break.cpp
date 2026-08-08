class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;

        int threes = n / 3;
        int remain = n % 3;
        if (remain == 1) {
            threes -= 1;
            remain = 4;
        } else if (remain == 0) {
            remain = 1;
        }
        return (int)(pow(3, threes) * remain);
    }
};

// class Solution {
// public:
// int t[57];
//     int integerBreak(int n) {
//         memset(t, -1, sizeof(t));
//         return dfs(n); }
//     int dfs(int n) {
//         if (n == 1)
//             return 1;
//         int first = 0;
//         int remain = 0;
//         int maxi = INT_MIN;
//         if(t[n]!=-1){
//             return t[n];
//         }
//         for (int i = 1; i < n; i++) {

//             first = i;
//             remain = n - i;
//             // stop
//             maxi = max(maxi, first * remain);
//             // break
//             maxi = max(maxi, i * dfs(n - i));
//         }
//         return t[n] = maxi;
//     }
// };
