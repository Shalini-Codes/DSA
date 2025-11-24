class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* leftmost = root;

        while (leftmost->left != NULL) {
            Node* head = leftmost;

            while (head != NULL) {
                // Connect left child to right child
                head->left->next = head->right;

                // Connect right child to next node's left child
                if (head->next != NULL) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};
