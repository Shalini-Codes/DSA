class Solution {
public:
    int sum = 0;

    TreeNode* bstToGst(TreeNode* root) {
        convert(root);
        return root;
    }

    void convert(TreeNode* node) {
        if (!node) return;

        // Visit right subtree (greater values first)
        convert(node->right);

        // Update current node
        sum += node->val;
        node->val = sum;

        // Visit left subtree
        convert(node->left);
    }
};
