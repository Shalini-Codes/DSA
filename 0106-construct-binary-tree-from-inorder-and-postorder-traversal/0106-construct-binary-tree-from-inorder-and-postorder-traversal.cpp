class Solution {
public:
    unordered_map<int, int> inMap;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd) return nullptr;

        // Last element in postorder is root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find position in inorder
        int inRoot = inMap[rootVal];

        // IMPORTANT: Build right subtree first, then left
        root->right = build(inorder, postorder, inRoot + 1, inEnd);
        root->left  = build(inorder, postorder, inStart, inRoot - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIndex = n - 1;

        // Store inorder indices for O(1) lookup
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;

        return build(inorder, postorder, 0, n - 1);
    }
};
