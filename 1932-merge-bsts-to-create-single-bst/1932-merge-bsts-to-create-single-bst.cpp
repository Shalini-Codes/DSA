class Solution {
public:
    unordered_map<int, TreeNode*> mp;

    bool dfs(TreeNode* root, long minVal, long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // If leaf and matches root of another tree, merge
        if (!root->left && !root->right && mp.count(root->val)) {
            TreeNode* temp = mp[root->val];
            root->left = temp->left;
            root->right = temp->right;
            mp.erase(root->val);
        }

        return dfs(root->left, minVal, root->val) &&
               dfs(root->right, root->val, maxVal);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaves;

        // Store all roots in map
        for (auto t : trees) {
            mp[t->val] = t;
        }

        // Collect all leaf values
        for (auto t : trees) {
            if (t->left) leaves.insert(t->left->val);
            if (t->right) leaves.insert(t->right->val);
        }

        // Find starting root (never appears as a leaf)
        TreeNode* root = nullptr;
        for (auto t : trees) {
            if (!leaves.count(t->val)) {
                root = t;
                break;
            }
        }

        if (!root) return NULL;

        mp.erase(root->val);

        // Validate and merge
        if (!dfs(root, LONG_MIN, LONG_MAX) || !mp.empty())
            return NULL;

        return root;
    }
};
