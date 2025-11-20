class Solution {
public:
    unordered_map<int, int> mp;  // stores inorder value -> index
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // Root value from preorder
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root index in inorder
        int inIndex = mp[rootVal];

        // Build left and right subtree
        root->left = build(preorder, inorder, inStart, inIndex - 1);
        root->right = build(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        // Build the map
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n - 1);
    }
};
