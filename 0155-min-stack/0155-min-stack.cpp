#include <stack>
using namespace std;

class MinStack {
    stack<int> st;     // main stack
    stack<int> minSt;  // stack to track minimums

public:
    MinStack() { }

    void push(int val) {
        st.push(val);
        // if minSt is empty or new value <= current min, push it to minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        // if top of main stack equals top of min stack, pop from both
        if (!st.empty()) {
            if (st.top() == minSt.top()) {
                minSt.pop();
            }
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
