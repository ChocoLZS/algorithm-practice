#include <list>
#include <unordered_map>
#include <utility>

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;
    explicit Node() : prev(nullptr), next(nullptr) {}
    explicit Node<T>(T data): data(data), prev(nullptr), next(nullptr) {
    }
};

template <typename T>
class DualList {
    Node<T> *head, *tail;  // 哑节点，不存数据
    int count;

public:
    DualList() : count(0) {
        head = new Node<T>();
        tail = new Node<T>();
        head->next = tail;
        tail->prev = head;
    }

    Node<T>* push_front(const T& data) {
        Node<T>* node = new Node<T>(data);
        insert_after(head, node);
        count++;
        return node;
    }

    void move_to_front(Node<T>* node) {
        remove(node);
        insert_after(head, node);
    }

    void pop_back() {
        if (count == 0) return;
        Node<T>* to_delete = tail->prev;
        remove(to_delete);
        count--;
        delete to_delete;
    }

    int size() const { return count; }

    Node<T>* back() const { return tail->prev; }

    ~DualList() {
        Node<T>* cur = head;
        while (cur) {
            Node<T>* next = cur->next;
            delete cur;
            cur = next;
        }
    }

private:
    void insert_after(Node<T>* pos, Node<T>* node) {
        node->next = pos->next;
        pos->next->prev = node;
        node->prev = pos;
        pos->next = node;
    }

    void remove(Node<T>* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

class LRUCache {
    DualList<std::pair<int, int>> dll;
    std::unordered_map<int, Node<std::pair<int, int>>*> map;
    int capacity;
public:
    LRUCache(int capacity): dll(), map() {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;
        auto nodeIt = it->second;
        dll.move_to_front(nodeIt);
        return nodeIt->data.second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) { // not found
            auto node = dll.push_front({key, value});
            map[key] = node;
            if (dll.size() > capacity) {
                map.erase(dll.back()->data.first);
                dll.pop_back();
            }
        } else { // found
            auto nodeIt = it->second;
            nodeIt->data.second = value;
            dll.move_to_front(nodeIt);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */