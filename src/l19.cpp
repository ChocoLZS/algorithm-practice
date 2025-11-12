#include "leetcode.hpp"

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
        ListNode* forward = head;
        ListNode* after = head;
        for (int i = 0;i < n;i++) {
            forward = forward->next;
        }

        if (forward == nullptr) {
            head = head->next;
            return head;
        }

        while (forward->next != nullptr) {
            forward = forward->next;
            after = after->next;
        }

        after->next = after->next->next;
        return head;
    }
};