#include <algorithm>
#include <utility>
#include <vector>

class MinStack {
    std::vector<std::pair<int, int>> stack;
public:
    MinStack(): stack() {
        
    }
    
    void push(int val) {
        if (stack.empty()) {
            stack.push_back({val, val});
        } else {
            stack.push_back({val, std::min(getMin(), val)});
        }
        
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */