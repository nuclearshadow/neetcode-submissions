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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* psuedo = new ListNode();
        psuedo->next = head;
        auto beforeGroup = psuedo;
        while (true) {
            auto nextGroup = beforeGroup;
            bool end = false;
            for (int i = 0; i < k; i++) {
                nextGroup = nextGroup->next;
                if (nextGroup == nullptr) {
                    end = true;
                    break;
                }
            }
            if (end) break;

            auto groupHead = beforeGroup->next;
            for (int i = 0; i < k - 1; i++) {
                attachAfter(beforeGroup, detachAfter(groupHead));
            }
            beforeGroup = groupHead;
        }
        return psuedo->next;
    }

    ListNode* detachAfter(ListNode* node) {
        auto detached = node->next;
        node->next = detached->next;
        return detached;
    }

    void attachAfter(ListNode* head, ListNode* node) {
        node->next = head->next;
        head->next = node;
    }
};
