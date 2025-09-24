class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // map element -> next greater element
        stack<int> st;
        
        for (int num : nums2) {
            // While current number is greater than stack top, it's the next greater for stack top
            while (!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // For remaining elements in stack, no next greater exists
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        // Build answer for nums1 based on the map
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }
        
        return ans;
    }
};
