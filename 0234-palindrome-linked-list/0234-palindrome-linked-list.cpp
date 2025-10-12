class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        slow->next = reverseList(slow->next);
        ListNode* second = slow->next;
        ListNode* first = head;

        // Step 3: Compare both halves
        while (second) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }

private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
