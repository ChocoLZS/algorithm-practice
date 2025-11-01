#include "leetcode.hpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        bool result = false;
        while (result == false && (fast != nullptr && fast->next != nullptr)) {
            if (slow == fast) result = true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return result;
    }
};