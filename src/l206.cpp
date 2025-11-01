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
    // iterator
    ListNode* reverseList_iterator(ListNode* head) {
        if (!head) return nullptr;
        ListNode* result_head = head;
        ListNode *curP = head;
        ListNode *preP = nullptr;
        while (curP) {
            curP = result_head->next;
            result_head->next = preP;
            preP = result_head;
            if (curP)
                result_head = curP;
        }
        return result_head;
    }

    // recursive 利用栈上的参数来反转
    ListNode* recursiveReverseList(ListNode* pre, ListNode* tail) {
        if (!pre) {
            return tail;
        }
        ListNode* reversed = recursiveReverseList(pre->next, pre);
        pre->next = tail;
        return reversed;
    }
    // recursive
    ListNode* reverseList(ListNode* head) {
        return recursiveReverseList(head, nullptr);
    }
};