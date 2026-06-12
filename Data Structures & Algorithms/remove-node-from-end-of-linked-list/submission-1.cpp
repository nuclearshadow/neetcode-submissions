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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        auto it = head;
        while (it != nullptr) {
            count++;
            it = it->next;
        }
        if (n == count) {
            return head->next;
        }
        int i = 1;
        it = head;
        while (i < count - n) {
            i++;
            it = it->next;
        }
        it->next = it->next->next;
        return head;
    }
};
