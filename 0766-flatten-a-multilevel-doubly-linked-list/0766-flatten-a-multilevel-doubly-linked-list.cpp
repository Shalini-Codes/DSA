/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            // Case 1: No child, just move to next
            if (!curr->child) {
                curr = curr->next;
                continue;
            }

            // Case 2: Node has a child
            Node* nextNode = curr->next;        // store next node
            Node* child = flatten(curr->child); // flatten child list

            // Connect curr and child
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;              // remove child pointer

            // Move to the end of flattened child list
            Node* temp = child;
            while (temp->next)
                temp = temp->next;

            // Connect the tail of child list to nextNode
            if (nextNode) {
                temp->next = nextNode;
                nextNode->prev = temp;
            }

            // Move curr forward
            curr = nextNode;
        }

        return head;
    }
};
