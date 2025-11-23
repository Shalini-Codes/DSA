#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    int K;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x : nums) {
            pq.push(x);
            if(pq.size() > K)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K)
            pq.pop();
        return pq.top();
    }
};
