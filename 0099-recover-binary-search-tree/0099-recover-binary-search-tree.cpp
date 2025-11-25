class Solution {
public:
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect violation
        if (prev && prev->val > root->val) {
            if (!first) {
                first = prev;      // first wrong node
            }
            second = root;        // second wrong node
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
