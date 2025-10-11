class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // Sort children's greed
        sort(s.begin(), s.end()); // Sort cookie sizes
        
        int i = 0; // child pointer
        int j = 0; // cookie pointer
        
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie satisfies the child
                i++; // move to next child
            }
            j++; // move to next cookie
        }
        
        return i; // number of content children
    }
};
