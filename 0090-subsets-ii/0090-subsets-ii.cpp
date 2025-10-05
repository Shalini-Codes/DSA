class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int start, vector<int>& current) {
        result.push_back(current);  // Add current subset

        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same recursive level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);             // Choose the element
            backtrack(nums, i + 1, current);        // Explore further
            current.pop_back();                     // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<int> current;
        backtrack(nums, 0, current);
        return result;
    }
};
