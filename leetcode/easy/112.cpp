#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(!root){
                return false;
            }
    
            if(!root->left && !root->right){                
                if(root->val == targetSum)
                    return true;
                return false;
            }
    
            if(hasPathSum(root->left, targetSum - root->val))
                return true;
            if(hasPathSum(root->right, targetSum - root->val))
                return true;

            return false;
        }
};

int main() {
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    // TreeNode* root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(11);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->right->right = new TreeNode(1);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution sol;
    
    // cout<<sol.hasPathSum(root, 5)<<endl;
    cout<<sol.hasPathSum(root, 1)<<endl;
    return 0;
}