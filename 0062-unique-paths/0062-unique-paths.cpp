class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int total = m + n - 2;
        int r = min(m - 1, n - 1);  // choose smaller to reduce computation

        for (int i = 1; i <= r; i++) {
            ans = ans * (total - r + i) / i;
        }

        return (int)ans;
    }
};
