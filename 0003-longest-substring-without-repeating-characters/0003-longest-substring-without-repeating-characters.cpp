class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // stores last index of each char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex[s[right]] >= left) {
                // character repeated, move left pointer
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
