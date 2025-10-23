class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length and the tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find new tail position
        k = k % length;  // If k > length
        int stepsToNewTail = length - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle and set new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
