class TreeAncestor {
private:
    vector<vector<int>> up;
    int LOG;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 20; // enough for n <= 10^5 (2^20 > 10^6)
        up.assign(n, vector<int>(LOG, -1));

        // 2^0 ancestor (immediate parent)
        for(int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Precompute 2^j ancestors
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                if(up[i][j-1] != -1)
                    up[i][j] = up[ up[i][j-1] ][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < LOG; j++) {
            if(node == -1) return -1;
            if(k & (1 << j)) {
                node = up[node][j];
            }
        }
        return node;
    }
};
