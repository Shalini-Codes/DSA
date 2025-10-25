#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> input, output; // two stacks

    MyQueue() {
        // constructor
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from in front of queue and returns that element.
    int pop() {
        // Move elements if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int front = output.top();
        output.pop();
        return front;
    }
    
    // Get the front element.
    int peek() {
        // Move elements if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    // Returns whether the queue is empty.
    bool empty() {
        return input.empty() && output.empty();
    }
};


