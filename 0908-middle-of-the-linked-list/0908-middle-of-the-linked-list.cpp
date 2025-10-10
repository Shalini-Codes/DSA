class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // move slow 1 step
            fast = fast->next->next;    // move fast 2 steps
        }

        return slow;  // slow is now at the middle
    }
};
