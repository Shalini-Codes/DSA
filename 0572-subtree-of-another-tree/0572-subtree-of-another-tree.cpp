class Solution {
public:
    // Helper function to check if two trees are identical
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;              // Both null → same
        if (!a || !b) return false;             // Only one null → not same
        if (a->val != b->val) return false;     // Values differ → not same

        // Check left and right subtrees
        return isSameTree(a->left, b->left) && 
               isSameTree(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;     // Empty root cannot contain subtree

        // If trees match at current node
        if (isSameTree(root, subRoot)) 
            return true;

        // Otherwise check in left or right subtrees
        return isSubtree(root->left, subRoot) || 
               isSubtree(root->right, subRoot);
    }
};
