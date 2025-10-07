/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for min-heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // smallest value has higher priority
        };

        // Min-heap (priority queue)
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Push the head of each list into the min-heap
        for (auto list : lists) {
            if (list != nullptr)
                pq.push(list);
        }

        // Dummy head for the merged linked list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Extract the smallest node one by one and push the next node
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr)
                pq.push(node->next);
        }

        return dummy->next;
    }
};
