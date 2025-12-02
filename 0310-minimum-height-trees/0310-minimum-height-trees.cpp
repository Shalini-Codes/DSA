class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};  // Only one node
        
        vector<int> degree(n, 0);
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Initialize queue with all leaves
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        vector<int> result;

        // Remove leaves layer-by-layer
        while (!q.empty()) {
            int size = q.size();
            result.clear();  // track current layer

            for (int i = 0; i < size; i++) {
                int leaf = q.front();
                q.pop();
                result.push_back(leaf);

                // Decrease degree of neighbors
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    // If becomes a leaf, push to queue
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return result;  // remaining 1–2 centroids
    }
};
