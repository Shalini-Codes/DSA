class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);      // 1. Visit left subtree
        ans.push_back(root->val);      // 2. Visit current node
        inorder(root->right, ans);     // 3. Visit right subtree
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
