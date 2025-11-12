class Solution {
public:
    // Helper function to check height and balance simultaneously
    int checkHeight(TreeNode* root) {
        if (!root) return 0; // Empty tree has height 0

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree not balanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree not balanced

        // If height difference > 1, tree is not balanced
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
