#include "leetcode.hpp"
#include <deque>
#include <queue>
#include <utility>
#include <vector>
#include <memory>

// 1. 手写一个堆试试，大根堆，顶部是最大元素，需要记录最大元素以及其坐标值


class Element {
    int index;
    int value;
public:
    bool operator==(const Element& other) const {
        return index == other.index && value == other.value;
    }
    bool operator>=(const Element& other) const {
        return value >= other.value;
    }
    bool operator>(const Element& other) const {
        return value > other.value;
    }
    bool operator<=(const Element& other) const {
        return value <= other.value;
    }
    bool operator<(const Element& other) const {
        return value < other.value;
    }
};

template <typename T>
class Heap { // big root tree like
    T data;
    std::unique_ptr<Heap<T>> left;
    std::unique_ptr<Heap<T>> right;
    const Heap<T>* find_node(T target) const {
        if (data == target) {
            return this;
        }
        Heap<T>* left_result = nullptr;
        if (left) {
            left_result = left->find_node(target);
        }
        if (left_result) return left_result;
        if (right) {
            return right->find_node(target);
        }
        return nullptr;
    }
public:

    Heap<T>(T data) {}

    void emplace(T data) { // 插左子树或右子树

    }

    const T top() const  {
        return data;
    }

    T pop() {
        //
    }

    ~Heap() {

    }
};

// template <typename T>
// class HeapVector {
//     T value
// };

// 2. 用单调队列，双端

class Solution {
public:
    std::vector<int> maxSlidingWindow_large_root_heap_tree(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        res.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++) {
            int current = nums[i];
            q.emplace(current, i);
            while (q.top().second <= i-k) { // 清理优先队列, 保持最大值始终在窗口内部
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }

    std::vector<int> maxSlidingWindow_priority_queue(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.emplace(nums[i], i);
        }
        res.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++) {
            int current = nums[i];
            q.emplace(current, i);
            while (q.top().second <= i-k) { // 清理优先队列, 保持最大值始终在窗口内部
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }

    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> q; // 存坐标, 坐标单调递增，但是 nums[i] 严格递减，保证最大值一定在窗口中，并且很方便的可以从左侧拿到
        for (int i = 0; i < k; i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        for (int i = k; i < nums.size(); i++) {
            while(!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            while(nums.front() < i - k) q.pop_front();
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};

int main() {
    printf("Welcome to LeetCode C++ solution template!\n");

    return 0;
}