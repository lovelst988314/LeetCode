#include<iostream>
#include<stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) {
    if(root == nullptr) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();
        if(temp->right != nullptr) st.push(temp->right);
        if(temp->left != nullptr) st.push(temp->left);
        temp->left = nullptr;
        if(!st.empty())
        temp->right = st.top();
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    return 0;
}