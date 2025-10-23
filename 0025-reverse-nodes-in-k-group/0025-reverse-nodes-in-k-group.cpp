class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Check if there are at least k nodes
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) return head; // not enough nodes to reverse

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Connect next reversed part
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: prev becomes new head
        return prev;
    }
};
