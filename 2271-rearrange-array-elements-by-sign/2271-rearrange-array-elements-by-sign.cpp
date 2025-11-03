class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        
        // Separate positive and negative numbers
        for (int num : nums) {
            if (num > 0) pos.push_back(num);
            else neg.push_back(num);
        }
        
        vector<int> ans;
        int i = 0, j = 0;
        
        // Alternate positive and negative numbers
        while (i < pos.size() && j < neg.size()) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }
        
        return ans;
    }
};
