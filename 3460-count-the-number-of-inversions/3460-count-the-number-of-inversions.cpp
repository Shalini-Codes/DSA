class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;

        // Sort requirements by end index
        sort(requirements.begin(), requirements.end());
        int m = requirements.size();
        int reqIndex = 0;

        vector<vector<int>> dp(n + 1, vector<int>(n * (n - 1) / 2 + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int maxInv = i * (i - 1) / 2;
            vector<long long> prefix(maxInv + 1, 0);

            prefix[0] = dp[i - 1][0];
            for (int j = 1; j <= maxInv; j++)
                prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % MOD;

            for (int j = 0; j <= maxInv; j++) {
                if (j < i)
                    dp[i][j] = prefix[j] % MOD;
                else
                    dp[i][j] = (prefix[j] - prefix[j - i] + MOD) % MOD;
            }

            // Apply requirement restriction if exists
            if (reqIndex < m && requirements[reqIndex][0] == i - 1) {
                int c = requirements[reqIndex][1];
                for (int j = 0; j <= maxInv; j++) {
                    if (j != c) dp[i][j] = 0;
                }
                reqIndex++;
            }
        }

        // Last requirement must be satisfied
        int lastCnt = requirements.back()[1];
        return dp[n][lastCnt];
    }
};
