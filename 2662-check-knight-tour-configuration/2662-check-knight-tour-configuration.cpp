class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // The knight must start at top-left cell (0,0)
        if (grid[0][0] != 0) return false;

        // Store positions of each move number
        vector<pair<int,int>> pos(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        // Check consecutive moves for valid knight jumps
        for (int k = 1; k < n * n; k++) {
            int r1 = pos[k-1].first, c1 = pos[k-1].second;
            int r2 = pos[k].first, c2 = pos[k].second;
            int dr = abs(r1 - r2), dc = abs(c1 - c2);

            // Knight moves in an "L" shape: (2,1) or (1,2)
            if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) {
                return false;
            }
        }

        return true;
    }
};
