#include "leetcode.hpp"
#include <unordered_set>
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
    // 朴素方法：记录当前节点是否出现
    ListNode *detectCycle_normal(ListNode *head) {
        std::unordered_set<ListNode*> set{};
        ListNode* curP = head;
        while (curP) {
            auto it = set.insert(curP);
            if (!it.second) {
                break;
            }
            curP = curP->next;
        }
        return curP;
    }

    // 快慢指针公式法
    /**
    * 假设环外为 a个节点
    * 相遇时经过b个节点
    * 剩下部分为c个节点，环总长为a+b
    
    * 那么当相遇时，假设快指针走了n圈：快指针走了 a + b + n * (b+c) = a + (n+1) * b + n * c
    可知，快指针走的步数为慢指针的2倍，所以有 a + (n+1) * b + n * c = 2 * (a+b)
    即 a = (n-1)*b + n*c = c + (n-1)(b+c)
    可以看见a和c有周期关系 （排除掉一整圈的因素） a与b相等
    那么，当相遇时，再让慢指针走，直至重叠，那么就是第一个入节点 
    */
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        // 初始化时有问题 slow == fast = head
        while (fast != nullptr && fast->next != nullptr && (slow != fast)) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        ListNode* res = head;
        while (res != slow) {
            res = res->next;
            slow = slow->next;
        }
        return res;
    }

    ListNode* detectCycle_official_fast_and_slow(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* res = head;
                while (res != slow) {
                    res = res->next;
                    slow = slow->next;
                }
                return res;
            }
        } 
        return nullptr;
    }
};