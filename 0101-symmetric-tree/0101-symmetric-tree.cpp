class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // Both are null -> symmetric
        if (!left && !right) return true;
        // Only one is null -> not symmetric
        if (!left || !right) return false;
        // Check current values and recurse
        return (left->val == right->val) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // Empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};
