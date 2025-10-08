class Solution {
public:
    vector<vector<string>> ans; // stores all valid board configurations

    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check left side of the same row
        for (int j = col - 1; j >= 0; j--) {
            if (board[row][j] == 'Q') return false;
        }

        // Check lower-left diagonal
        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true; // position is safe
    }

    void solve(int col, vector<string> &board, int n) {
        // Base case: All queens placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in each row for current column
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q'; // place queen
                solve(col + 1, board, n); // move to next column
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); // initialize empty board
        solve(0, board, n);
        return ans;
    }
};
