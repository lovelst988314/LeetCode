#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q) return root;
    TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightnode = lowestCommonAncestor(root->right, p, q);

    if(leftnode != nullptr && rightnode == nullptr) return leftnode;
    if(leftnode == nullptr && rightnode != nullptr) return rightnode;
    if(leftnode != nullptr && rightnode != nullptr) return root;
    
    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    cout << lowestCommonAncestor(root, root->left, root->right)->val << endl;
}