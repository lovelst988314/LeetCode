#include<iostream>
#include<vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummpy = new ListNode();
    ListNode* temp = dummpy;

    while(true) {
        int num = INT_MAX;
        int minnum = -1;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr && lists[i]->val < num) {
                num = lists[i]->val;
                minnum = i;
            }
        }
        if(minnum == -1) break;

        temp->next = lists[minnum];
        temp = temp->next;
        lists[minnum] = lists[minnum]->next;
    }
    return dummpy->next;
}

int main() {
    vector<ListNode*> lists;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(4);
    ListNode* node3 = new ListNode(5);

    ListNode* node4 = new ListNode(1);
    ListNode* node5 = new ListNode(3);
    ListNode* node6 = new ListNode(4);

    ListNode* node7 = new ListNode(2);
    ListNode* node8 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;

    node4->next = node5;
    node5->next = node6;

    node7->next = node8;

    lists.push_back(node1);
    lists.push_back(node4);
    lists.push_back(node7);

    ListNode* res = mergeKLists(lists);
    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
