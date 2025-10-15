class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                // Step 2: Find cycle start
                ListNode* ptr1 = head;
                while (ptr1 != slow) {
                    ptr1 = ptr1->next;
                    slow = slow->next;
                }
                return ptr1; // start of cycle
            }
        }
        return nullptr; // no cycle
    }
};
