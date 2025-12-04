class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;

        for(int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            mp[size].push_back(i);

            // When enough people are collected to form a group
            if(mp[size].size() == size) {
                result.push_back(mp[size]);
                mp[size].clear();  // reset for next group of same size
            }
        }

        return result;
    }
};
