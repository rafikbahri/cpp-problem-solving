#include<iostream>

using namespace std;

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return root;
        if(val > root->val)
            return searchBST(root->right, val);
        if(val < root->val)
            return searchBST(root->left, val);
        return root;
    }
};

int main(){
    TreeNode leaf3 = TreeNode(3);
    TreeNode leaf1 = TreeNode(1);
    TreeNode node2 = TreeNode(2, &leaf1, &leaf3);
    TreeNode leaf7 = TreeNode(7);
    TreeNode root = TreeNode(2, &node2, &leaf7);
    
    Solution* obj = new Solution();
    TreeNode* res = obj->searchBST(&root, 2);
    // TreeNode* res = obj->searchBST(&root, 10);

    cout << (res != nullptr ? res->val : -1) << endl;
    return 0;
}