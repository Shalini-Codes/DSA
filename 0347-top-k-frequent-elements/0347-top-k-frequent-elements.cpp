class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        
        // Count frequency
        for(int num : nums) 
            freq[num]++;
        
        // Bucket where index = frequency
        vector<vector<int>> bucket(nums.size() + 1);
        
        for(auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }
        
        vector<int> result;
        
        // Collect from highest frequency
        for(int i = bucket.size() - 1; i >= 0 && result.size() < k; i--) {
            for(int num : bucket[i]) {
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        
        return result;
    }
};
