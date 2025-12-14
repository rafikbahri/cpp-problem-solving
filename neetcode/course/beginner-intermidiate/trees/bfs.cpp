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
    vector<int> arr;
    int count = 0;
    int res = 0;

    void bfs(TreeNode* root){
        if(root){
            cout<<root->val<<" ";
        }
        if(root->left){
            bfs(root->left);
        }
        if(root->right){
            bfs(root->right);
        }
    }

    int depth(TreeNode* root){
        
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

    Solution sol;

    sol.bfs(root);

    return 0;
}