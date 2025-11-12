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
    ListNode* swapPairs_1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* ptr_left = head;
        ListNode* ptr_right = head->next;
        // swap
        ptr_left->next = ptr_right->next;
        ptr_right->next = ptr_left;
        // make sure ptr_left is behind ptr_right;
        ListNode* tmp = ptr_left;
        ptr_left = ptr_right;
        ptr_right = tmp;
        head = ptr_left;
        ListNode* before = ptr_right;
        while (ptr_right->next != nullptr && ptr_right->next->next != nullptr) {
            before = ptr_right;
            ptr_right = ptr_right->next->next;
            ptr_left = ptr_left->next->next;
            ptr_left->next = ptr_right->next;
            ptr_right->next = ptr_left;
            tmp = ptr_left;
            ptr_left = ptr_right;
            ptr_right = tmp;
            before->next = ptr_left;
        }
        return head;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next && temp->next->next) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummy->next;
    }
};