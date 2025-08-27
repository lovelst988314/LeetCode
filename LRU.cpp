#include <iostream>
#include <unordered_map>

using namespace std;

struct Dlinknode {
    int key, value;
    Dlinknode* next;
    Dlinknode* pre;
    Dlinknode() : key(0), value(0), next(nullptr), pre(nullptr) {};
    Dlinknode(int _key, int _value) : key(_key), value(_value), next(nullptr), pre(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        size = 0;
        head = new Dlinknode();
        tail = new Dlinknode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            // 要移动到最前面（原位置删除）节点放到最前面
            Dlinknode* temp = mp[key];
            deletenode(temp);
            movetohead(temp);
            return temp->value;

        } else return -1;   
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            Dlinknode* node = new Dlinknode(key, value);
            mp[key] = node;
            movetohead(node);
            size++;
            if(size > _capacity) {
                Dlinknode* temp = taildelete();
                mp.erase(temp->key);
                size--;

            }
        } else {
            Dlinknode* temp = mp[key];
            temp->value = value;
            deletenode(temp);
            movetohead(temp);
        }
    }
    void deletenode(Dlinknode* node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }
    void movetohead(Dlinknode* node) {
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }
    Dlinknode* taildelete() {
        Dlinknode* node = tail->pre;
        deletenode(node);
        return node;
    }
private: 
    int size;
    int _capacity;
    Dlinknode* head;
    Dlinknode* tail;
    unordered_map<int, Dlinknode*> mp; // 键:指向该节点的指针
};

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;
    cache->put(3, 3);
    cout << cache->get(2) << endl;
    cache->put(4, 4);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
}