class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Step 2: Fill initial graph distances
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Step 3: Floyd–Warshall to compute all-pairs shortest path
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Step 4: Find city with minimum number of reachable cities
        int minReachable = INT_MAX;
        int answerCity = -1;

        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    count++;
            }

            // Choose city with smallest count, and on tie choose larger index
            if (count <= minReachable) {
                minReachable = count;
                answerCity = i;
            }
        }

        return answerCity;
    }
};
