class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both nodes are null
        if (!p && !q) return true;
        
        // Case 2: one is null, other is not
        if (!p || !q) return false;
        
        // Case 3: check current node values and recursively check subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
