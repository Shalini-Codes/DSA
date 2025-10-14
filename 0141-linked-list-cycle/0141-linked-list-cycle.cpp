class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) 
            return false;  // empty list or single node cannot form a cycle
        
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) {         // cycle detected
                return true;
            }
        }
        return false;  // reached end, no cycle
    }
};
