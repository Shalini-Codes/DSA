class Solution {
public:
    TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        // Recurse on right subtree first
        flatten(root->right);
        
        // Then recurse on left subtree
        flatten(root->left);
        
        // Rewiring pointers
        root->right = prev;
        root->left = NULL;
        
        // Move prev pointer to current node
        prev = root;
    }
};
