class Solution {
public:
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        // Get max path sum from left and right (ignore negative paths)
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // Update global maximum including current node as root of path
        maxSum = max(maxSum, root->val + left + right);

        // Return max path going down from current node
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
