#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), rankv(n+1, 0);
        for (int i = 1; i <= n; ++i) parent[i] = i;

        function<int(int)> findp = [&](int x){
            if (parent[x] != x) parent[x] = findp(parent[x]);
            return parent[x];
        };

        auto unite = [&](int a, int b)->bool{
            int pa = findp(a), pb = findp(b);
            if (pa == pb) return false;
            if (rankv[pa] < rankv[pb]) swap(pa, pb);
            parent[pb] = pa;
            if (rankv[pa] == rankv[pb]) rankv[pa]++;
            return true;
        };

        vector<int> ans;
        for (auto &e : edges) {
            if (!unite(e[0], e[1])) ans = e; // overwrite — keeps the last redundant edge
        }
        return ans;
    }
};
