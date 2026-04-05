class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        // DFS function
        function<bool(int,int,int)> dfs = [&](int i, int j, int idx) {
            if (idx == word.size()) return true; // all chars matched
            if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) 
                return false;
            
            char temp = board[i][j];
            board[i][j] = '#'; // mark visited
            
            // explore neighbors
            bool found = dfs(i+1, j, idx+1) || 
                         dfs(i-1, j, idx+1) || 
                         dfs(i, j+1, idx+1) || 
                         dfs(i, j-1, idx+1);
            
            board[i][j] = temp; // backtrack
            return found;
        };
        
        // try starting DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};
