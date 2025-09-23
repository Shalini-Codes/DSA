class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // Count frequency of s1
        for (char c : s1) {
            count1[c - 'a']++;
        }

        int window = s1.size();

        // Initial window in s2
        for (int i = 0; i < window; i++) {
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        // Sliding window
        for (int i = window; i < s2.size(); i++) {
            // Add new char
            count2[s2[i] - 'a']++;
            // Remove old char
            count2[s2[i - window] - 'a']--;

            if (count1 == count2) return true;
        }

        return false;
    }
};
