#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
LRUCache(int capacity) {
    _capacity = capacity;
    size = 0;
    head = new DLinkedNode();
    tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
}

int get(int key) {
    if(cache.find(key) != cache.end()) {
        DLinkedNode* node = cache[key];
        movetoHead(node);
        return node->value;
    } else {
        return -1;
    }
}

void put(int key, int value) {
    if(cache.find(key) != cache.end()) {
        // 找到了
        DLinkedNode* node = cache[key];
        node->value = value;
        movetoHead(node);
    } else {
        // 没找到
        DLinkedNode* newnode = new DLinkedNode(key,value);
        cache.insert({key,newnode});
        addToHead(newnode);
        size++;
        if(size > _capacity) {
            DLinkedNode* temp = removeTail();
            cache.erase(temp->key);
            size--;
        }
    }
}

private:
    struct DLinkedNode {
        int key, value;
        DLinkedNode* prev;
        DLinkedNode* next;
        DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
        DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, DLinkedNode*> cache; // key DLinkedNode
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int _capacity;
void removeNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    // 因为增加了head 和 tail所以数据节点不会为
}
void addToHead(DLinkedNode* node) {
    node->next = head->next;
    head->next->prev = node;
    node->prev = head;
    head->next = node;
}
void movetoHead(DLinkedNode* node) {
    removeNode(node);
    addToHead(node);
}
DLinkedNode* removeTail() {
    DLinkedNode* node = tail->prev;
    removeNode(node);
    return node;
}
};

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(1,1);
    cache->put(2,2);
    cout << cache->get(1) << endl;
    cache->put(3,3);
    cout << cache->get(2) << endl;
    cache->put(4,4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
}
// 函数签名 vs 函数体的解析时机
// 函数签名在类定义中解析
// 函数体在类定义中解析
