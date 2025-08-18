#include<iostream>

using namespace std;

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
Node* copyRandomList(Node* head) {
    if(head == nullptr) return nullptr;
    for(Node* node = head; node != nullptr; node = node->next->next) {
        Node* newnode = new Node(node->val);
        newnode->next = node->next;
        node->next = newnode; 
    }
    Node* result = head->next;
    for(Node* node = head; node != nullptr; node = node->next) {
        Node* temp1 = node->next;
        Node* temp2 = node->random;
        node->next = temp1->next;
        if(node->next != nullptr) {
            temp1->next = node->next->next;
        } else temp1->next = nullptr;
        if(temp2 != nullptr) {
            temp1->random = node->random->next;
        }else temp1->random = nullptr;
    }
    return result;
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random =  head->next->next;
    head->next->next->next->next->random = head;

    for(Node* node = head; node != nullptr; node = node->next) {
        cout << "val: " << node->val << " ";
        if(node->random != nullptr) {
            cout << "random: " << node->random->val << endl;
        } else cout << "random: " << "null" << endl;
    }

    cout << "--------------------------------------------------" << endl;   

    Node* result = copyRandomList(head);
    for(Node* node = result; node != nullptr; node = node->next) {
        cout << "val: " << node->val << " ";
        if(node->random != nullptr) {
            cout << "random: " << node->random->val << endl;
        } else cout << "random: " << "null" << endl;
    }
}

