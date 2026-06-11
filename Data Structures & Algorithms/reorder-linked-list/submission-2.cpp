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
        if (head->next == nullptr) {
            return;
        }
        auto it = head, mid = head;
        while (it != nullptr && it->next != nullptr) {
            mid = mid->next;
            it = it->next->next;
        }
        auto rev = reverse(mid->next);
        mid->next = nullptr;

        it = head;
        while (rev != nullptr) {
            auto next = it->next;
            it->next = rev;
            rev = rev->next;
            it->next->next = next;
            it = next;
        }
    }

    ListNode* reverse(ListNode* head) {
        auto newhead = head;
        while (head->next != nullptr) {
            auto next = head->next;
            head->next = next->next;
            next->next = newhead;
            newhead = next;
        }
        return newhead;
    }
};
