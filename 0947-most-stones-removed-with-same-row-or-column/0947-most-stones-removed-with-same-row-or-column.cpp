class Solution {
public:
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    void unionSet(int a, int b, vector<int> &parent, vector<int> &rank) {
        a = findParent(a, parent);
        b = findParent(b, parent);

        if (a != b) {
            if (rank[a] < rank[b]) parent[a] = b;
            else if (rank[a] > rank[b]) parent[b] = a;
            else {
                parent[b] = a;
                rank[a]++;
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int offset = 10001; // to separate rows and columns

        vector<int> parent(20005);
        vector<int> rank(20005, 0);

        // Initialize parents
        for (int i = 0; i < 20005; i++) parent[i] = i;

        unordered_set<int> groups;

        for (auto &s : stones) {
            int row = s[0];
            int col = s[1] + offset;

            unionSet(row, col, parent, rank);
        }

        // Count unique parents (connected components)
        for (auto &s : stones) {
            int row = s[0];
            groups.insert(findParent(row, parent));
        }

        int components = groups.size();
        int total = stones.size();

        return total - components;
    }
};
