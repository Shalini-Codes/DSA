#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;  // stores coordinates of rotten oranges
        int fresh = 0;           // count of fresh oranges
        int minutes = 0;
        
        // Step 1: Push all initially rotten oranges into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        
        // Directions: up, down, left, right
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        // Step 2: BFS traversal — rotting spreads level by level (minute by minute)
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    
                    // If within bounds and fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;   // make it rotten
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            minutes++; // one round (minute) completed
        }
        
        // If there are still fresh oranges, return -1
        return (fresh == 0) ? minutes : -1;
    }
};
