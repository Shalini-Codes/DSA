class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            TreeNode* node;

            // Traverse all nodes of the current level
            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();

                // Push children
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // The last node processed at this level is the right view node
            ans.push_back(node->val);
        }

        return ans;
    }
};
