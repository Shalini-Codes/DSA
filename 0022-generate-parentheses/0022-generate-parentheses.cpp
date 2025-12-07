class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        // If the current string is complete
        if(current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // If we can still add an opening bracket
        if(open < n) {
            backtrack(current + '(', open + 1, close, n);
        }

        // If we can add a closing bracket (only when close < open)
        if(close < open) {
            backtrack(current + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};
