class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        // As maximum
        {
            vector<int> left(n), right(n);
            stack<int> st;
            
            // Previous Greater (strict)
            for (int i = 0; i < n; i++) {
                while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
                left[i] = st.empty() ? (i + 1) : (i - st.top());
                st.push(i);
            }
            
            while (!st.empty()) st.pop();
            
            // Next Greater or Equal
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
                right[i] = st.empty() ? (n - i) : (st.top() - i);
                st.push(i);
            }
            
            for (int i = 0; i < n; i++) {
                ans += (long long)nums[i] * left[i] * right[i];
            }
        }
        
        // As minimum
        {
            vector<int> left(n), right(n);
            stack<int> st;
            
            // Previous Smaller (strict)
            for (int i = 0; i < n; i++) {
                while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
                left[i] = st.empty() ? (i + 1) : (i - st.top());
                st.push(i);
            }
            
            while (!st.empty()) st.pop();
            
            // Next Smaller or Equal
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
                right[i] = st.empty() ? (n - i) : (st.top() - i);
                st.push(i);
            }
            
            for (int i = 0; i < n; i++) {
                ans -= (long long)nums[i] * left[i] * right[i];
            }
        }
        
        return ans;
    }
};
