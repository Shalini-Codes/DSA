class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;            // current level
        int maxLevel = 1;         // answer level
        long long maxSum = LLONG_MIN;

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;

            // process all nodes of this level
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // update answer if this level has larger sum
            if(sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
};
