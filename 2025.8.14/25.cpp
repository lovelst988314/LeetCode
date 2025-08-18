#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;    

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

pair<ListNode*, ListNode*> reverse(ListNode* start, ListNode* end) {
    ListNode* pre = end->next;
    ListNode* node = start;
    while(pre != end) {
        ListNode* temp = node->next;
        node->next = pre;
        pre = node;
        node = temp;
    }
    return {end, start};
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(-1, head);
    ListNode* pre = dummy;
    while(head) {
        ListNode* tail = pre;
        for(int i = 0; i < k; ++i) {
            tail = tail->next;
            if(tail == nullptr) return dummy->next;
        }
        ListNode* nexthead = tail->next;
        pair<ListNode*, ListNode*> result = reverse(head, tail);
        head = result.first;
        tail = result.second;

        pre->next = head;
        tail->next = nexthead;
        pre = tail;
        head = nexthead;
    }
    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* result = reverseKGroup(head, k);
    while(result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
