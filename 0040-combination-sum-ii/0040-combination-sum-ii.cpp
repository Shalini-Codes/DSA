class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }

private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < (int)candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break; // pruning

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, path, res); // i+1 (use once)
            path.pop_back();
        }
    }
};
