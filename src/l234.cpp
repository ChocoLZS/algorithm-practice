#include <leetcode.hpp>
#include <vector>

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
    bool isPalindrome_array(ListNode* head) {
        std::vector<int> array;
        ListNode* curP = head;
        while (curP) {
            array.push_back(curP->val);
            curP = curP->next;
        }
        int n = array.size();
        for (int i = 0;i < (n >> 1); i++) {
            if (array[i] != array[n-i]) {
                return false;
            } 
        }
        return true;
    }

    ListNode* half(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* curP = head;
        ListNode* nextP = head->next;
        while (nextP) {
            ListNode* tmpP = nextP->next;
            nextP->next = curP;
            curP = nextP;
            nextP = tmpP;
        }
        return curP;
    }

    // 快慢
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        ListNode* firstHalfEnd = half(head);
        ListNode* endOfList = reverseList(firstHalfEnd->next);
        ListNode *leftP = head, *rightP = endOfList;
        while (leftP != firstHalfEnd) {
            if (leftP->val != rightP->val) return false;
            leftP = leftP->next;
            rightP = rightP->next;    
        }
        if (leftP->val != rightP->val) return false;
        reverseList(rightP == firstHalfEnd ? firstHalfEnd->next : rightP);
        return true;
    }
};