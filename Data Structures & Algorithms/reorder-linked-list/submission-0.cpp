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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        auto it = head;
        while (it != nullptr) {
            s.push(it);
            it = it->next;
        }

        it = head;
        while (it->next != nullptr) {
            auto next = it->next;
            auto top = s.top(); s.pop();
            if (next == top) break;
            it->next = top;
            top->next = next;
            s.top()->next = nullptr;
            it = next;
        }
    }
};
