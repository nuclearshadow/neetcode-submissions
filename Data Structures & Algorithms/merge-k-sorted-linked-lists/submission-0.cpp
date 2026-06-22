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
        ListNode* head = nullptr;
        ListNode* end = nullptr;
        while (true) {
            int minL = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && (minL == -1 || lists[i]->val < lists[minL]->val)) {
                    minL = i;
                }
            }
            if (minL == -1) break;
            if (end != nullptr) {
                end->next = lists[minL];
            }
            end = lists[minL];
            lists[minL] = lists[minL]->next;
            if (head == nullptr) head = end;
        }
        return head;
    }
};
