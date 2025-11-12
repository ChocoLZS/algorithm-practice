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
    int handle_val(ListNode* node) {
        int result = 0;
        if (node->val >= 10) {
            result = node->val / 10;
            node->val = node->val % 10;
        }
        return result;

    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            tail->next = new ListNode( l1->val + l2->val + handle_val(tail));
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // next recursive
        ListNode* next_ptr = l1 == nullptr ? l2 : l1;
        while (next_ptr != nullptr) {
            tail->next = new ListNode( next_ptr->val + handle_val(tail));
            tail = tail->next;
            next_ptr = next_ptr->next;
        }
        int more = handle_val(tail);
        if (more > 0) {
            tail->next = new ListNode(more);
            tail = tail->next;
        }
        return dummy.next;
    }
};