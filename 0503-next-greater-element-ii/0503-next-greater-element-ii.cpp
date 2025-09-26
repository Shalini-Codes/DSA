class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1); // Initialize all with -1
        stack<int> st; // Store indices

        for (int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n) {
                st.push(i); // only push first round indices
            }
        }
        return res;
    }
};
