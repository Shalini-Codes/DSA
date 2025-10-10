class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // previous node
        ListNode* curr = head;      // current node
        
        while (curr != nullptr) {
            ListNode* next = curr->next; // store next node
            curr->next = prev;           // reverse pointer
            prev = curr;                 // move prev forward
            curr = next;                 // move curr forward
        }
        
        return prev; // new head
    }
};
