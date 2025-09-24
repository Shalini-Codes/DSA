#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sorted version as key
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &entry : mp) {
            result.push_back(entry.second);
        }

        return result;
    }
};
