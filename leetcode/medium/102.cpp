#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            
        }
};

int main() {
    // Create the tree: [5,3,6,2,4,null,null,1]
    //        5
    //       / \
    //      3   6
    //     / \
    //    2   4
    //   /
    //  1
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(4);
    // root->left->right = new TreeNode(2);
        
    Solution sol;

    return 0;
}