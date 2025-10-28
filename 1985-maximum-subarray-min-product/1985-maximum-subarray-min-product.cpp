#include <vector>
#include <stack>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        
        // Prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];
        
        vector<int> left(n), right(n);
        stack<int> st;
        
        // Find previous smaller element
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Find next smaller element
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        long long res = 0;
        
        // Calculate max min-product
        for (int i = 0; i < n; ++i) {
            long long sum = prefix[right[i]] - prefix[left[i] + 1];
            long long minProduct = sum * nums[i];
            res = max(res, minProduct);
        }
        
        return res % MOD;
    }
};


