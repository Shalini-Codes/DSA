class Solution {
public:
    int m, n;
    vector<vector<int>> vis;

    bool dfs(int x, int y, int px, int py, vector<vector<char>>& grid) {
        vis[x][y] = 1;  // mark visited
        
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        for (auto& d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];

            // boundary check
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            // must match the same character
            if (grid[nx][ny] != grid[x][y]) continue;

            // if this neighbor is visited and not parent → cycle found
            if (vis[nx][ny]) {
                if (!(nx == px && ny == py)) return true;
            } 
            else {
                // continue DFS
                if (dfs(nx, ny, x, y, grid)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));

        // check each unvisited cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid)) return true;
                }
            }
        }
        return false;
    }
};
