class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;  // to store value of previous node during inorder traversal
        inorder(root, prev, minDiff);
        return minDiff;
    }

    void inorder(TreeNode* node, int &prev, int &minDiff) {
        if (!node) return;

        // Left subtree
        inorder(node->left, prev, minDiff);

        // Process current node
        if (prev != -1) {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;

        // Right subtree
        inorder(node->right, prev, minDiff);
    }
};
