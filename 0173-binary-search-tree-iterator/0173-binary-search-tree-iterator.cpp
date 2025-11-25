class BSTIterator {
private:
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while(node != nullptr) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();

        if(curr->right != nullptr)
            pushLeft(curr->right);

        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
