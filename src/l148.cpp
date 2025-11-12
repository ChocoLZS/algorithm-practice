#include "leetcode.hpp"
#include <algorithm>
#include <utility>
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
// normal, time: O(nlogn + n)  space: O(n)
    ListNode* sortList_normal(ListNode* head) {
        if (head == nullptr) return nullptr;
        std::vector<ListNode*> nodes;
        for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            nodes.push_back(ptr);
        }
        std::sort(nodes.begin(), nodes.end(), [](const ListNode* a, const ListNode* b) {
            return a->val < b->val;
        });
        for (int i = 0;i < nodes.size() - 1;i++) {
            nodes[i]->next = nodes[i+1];
        }
        nodes.back()->next = nullptr;
        return nodes[0];
    }

    // 这个很关键，拆又合并
    ListNode* findMidAndSplit(ListNode* list) {
        if (list == nullptr) return nullptr;
        ListNode* slow = list;
        ListNode* fast = list;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* res = slow->next;
        slow->next = nullptr;
        return res;
    }
    
    // 递归的归并排序，栈深度是 n/2
    // 合并链表，升序
    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = findMidAndSplit(head);
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(mid);

        return mergeList(left, right);

    }

    // 1. 找中点middle(start, end); middle
    // 2. 区分start end
    ListNode* sortList_recursive(ListNode* head) {
        return mergeSort(head);
    }

    int getLength(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p != nullptr; p = p->next) len++;
        return len;
    }

    // 从 head 切出前 n 个节点，返回剩余部分
    ListNode* cut(ListNode* head, int n) {
        // 走 n-1 步到达第 n 个节点
        // 断开并返回第 n+1 个节点
        int count = 0;
        ListNode* ptr = head;
        while (count < n && ptr != nullptr) {
            count++;
            ptr = ptr->next;
        }

        if (ptr == nullptr) return nullptr; // n > list length
        ListNode* res = ptr->next;
        ptr->next = nullptr;
        return res;
    }
    ListNode* sortList_iterator(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        int len = getLength(head);
        for (int size = 1; size < len; size = size * 2) {
            ListNode* cur = dummy.next;
            ListNode* tail = &dummy;
            while (cur != nullptr) {
                ListNode* left = cur;
                ListNode* right = cut(cur, size);
                cur = cut(right, size);
            }
        }
        return mergeSort(head);
    }

};