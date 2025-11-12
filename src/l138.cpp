// #include "leetcode.hpp"
#include <cstddef>
#include <unordered_map>
#include <vector>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
// not poor, 
// std::unordered_map -> (Node* -> Node*)
    Node* copyRandomList_poor(Node* head) {
        if (head == nullptr) return head;
        Node dummy(0);
        std::unordered_map<Node*, int> index_map;
        std::vector<Node*> node_arr;
        int i = 0;
        Node* ptr = head;
        Node* res_ptr = &dummy;
        while (ptr != nullptr) {
            index_map.emplace(ptr, i);
            res_ptr->next = new Node(ptr->val);
            res_ptr = res_ptr->next;
            node_arr.push_back(res_ptr);

            i++;
            ptr = ptr->next;
        }
        ptr = head;
        res_ptr = dummy.next;
        while (ptr != nullptr) {
            if (ptr->random != nullptr) {
                auto it = index_map.find(ptr->random);
                res_ptr->random = node_arr[it->second];
            }
            ptr = ptr->next;
            res_ptr = res_ptr->next;
        }
        return dummy.next;
    }
    // 遍历三次：1. 在所有的节点之后复制节点
    // 2. 复制节点指向random
    // 3. 提取复制后的链表
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        // 复制节点
        for (Node* ptr = head; ptr != nullptr;) {
            Node* tmp_ptr = ptr;
            ptr = ptr->next;
            tmp_ptr->next = new Node(tmp_ptr->val);
            tmp_ptr->next->next = ptr;
        }
        // 更改random
        for (Node* ptr = head; ptr != nullptr; ptr = ptr->next->next) {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
        }
        // 提取结果
        Node dummy(0);
        Node* res_ptr = &dummy;
        for (Node* ptr = head; ptr != nullptr; ) {
            Node* restore_ptr = ptr;
            res_ptr->next = ptr->next;
            ptr = ptr->next->next;
            res_ptr = res_ptr->next;
            // 复原原有链表
            restore_ptr->next = restore_ptr->next->next;
        }
        return dummy.next;
    }
};