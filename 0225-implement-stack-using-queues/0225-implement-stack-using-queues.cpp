#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {
    }
    
    void push(int x) {
        // Step 1: Push to q2
        q2.push(x);
        
        // Step 2: Move everything from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }
    
    int pop() {
        if (q1.empty()) return -1; // should not happen in valid usage
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
