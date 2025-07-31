#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* temp = head;
    int num = 0;
    while(l1 != nullptr && l2 != nullptr) {
        int ans = (num + l1->val + l2->val);
        temp->next = new ListNode(ans%10);
        num = ans/10;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if(l1 == nullptr) {
        while(l2 != nullptr) {
            int ans = (num + l2->val);
            temp->next = new ListNode(ans%10);
            num = ans/10;
            temp = temp->next;
            l2 = l2->next;
        }
    }
    if(l2 == nullptr) {
        while(l1 != nullptr) {
            int ans = (num + l1->val);
            temp->next = new ListNode(ans%10);
            num = ans/10;
            temp = temp->next;
            l1 = l1->next;
        }
    }
    if(l1 == nullptr && l2 == nullptr && num == 1) {
        temp->next = new ListNode(1);
    } 
    return head->next;
}

int main () {
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);
    ListNode* ans = addTwoNumbers(l1, l2);
    while(ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
}


