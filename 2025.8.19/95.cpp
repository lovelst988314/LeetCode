#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<TreeNode*> generateTree(int start, int end) {
    if(start > end) return {nullptr};
    
    vector<TreeNode*> alltrees;
    for(int i = start; i <= end; ++i) {
        vector<TreeNode*> lefttree = generateTree(start, i-1);
        vector<TreeNode*> righttree = generateTree(i+1, end);

        for(auto& left : lefttree) {
            for(auto& right : righttree) {
                TreeNode* cur = new TreeNode(i);
                cur->left = left;
                cur->right = right;
                alltrees.emplace_back(cur);
            }
        }
    }
    return alltrees;
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    if(n < 1) return result;
    result = generateTree(1,n);
    return result;
}

int main() {
    int n = 1;
    vector<TreeNode*> result = generateTrees(n);
    
    return 0;
}