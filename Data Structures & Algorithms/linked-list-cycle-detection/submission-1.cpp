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
    bool hasCycle(ListNode* head) {
        set<ListNode*> seen;
        int i = 0;
        while (head != nullptr) {
            seen.insert(head);
            if (seen.contains(head->next)) {
                return true;
            }
            i++;
            head = head->next;
        }
        return false;
    }
};
