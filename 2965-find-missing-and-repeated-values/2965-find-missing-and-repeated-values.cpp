class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
 int n = grid.size();
 long long N = n * n;

 long long sum = 0, sumSq = 0;

 for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        sum += grid[i][j];
        sumSq += (long long)grid[i][j] * grid[i][j];
    }
 }   

 long long S = N * (N + 1) / 2;
 long long P = N * (N + 1) * (2 * N + 1) / 6;

 long long val1 = S - sum;
 long long val2 = P - sumSq;

 val2 = val2 / val1;

 long long missing = (val1 + val2) / 2;
 long long repeating = missing - val1;

 return {(int)repeating, (int)missing};    
    }
};