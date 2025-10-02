class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int a : asteroids) {
            bool alive = true;
            
            // Collision check only when a is moving left and stack top is moving right
            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > abs(st.top())) {
                    st.pop(); // top asteroid explodes
                    continue; // still need to check further collisions
                }
                else if (abs(a) == abs(st.top())) {
                    st.pop(); // both explode
                }
                alive = false; // current asteroid destroyed
                break;
            }
            
            if (alive) st.push(a);
        }
        
        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
