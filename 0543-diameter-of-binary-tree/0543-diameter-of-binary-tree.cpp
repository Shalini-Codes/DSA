class Solution {
public:
    int diameter = 0; // Global variable to store the maximum diameter
    
    int height(TreeNode* root) {
        if (!root) return 0; // Base case: empty tree
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Update the diameter at this node
        diameter = max(diameter, leftHeight + rightHeight);
        
        // Return height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
