class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // No reversal needed

        // Step 1: Create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Step 2: Move 'prev' just before the left position
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 3: Start reversing
        ListNode* curr = prev->next;
        ListNode* nextNode = nullptr;

        // Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        // Step 4: Return the new head
        return dummy->next;
    }
};
