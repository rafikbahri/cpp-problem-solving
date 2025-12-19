#include <iostream>
#include <vector>
#include <queue>

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
    void postorderTraversal(TreeNode* root){
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout<<root->val<<" ";
        }
    }

    vector<int> bfs(TreeNode* root){
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            res.push_back(front->val);
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
            q.pop();
        }
        return res;
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

    cout<<"Breadth First Serach - BFS"<<endl;

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->left = new TreeNode(-1);


    Solution sol;
    vector<int> res = sol.bfs(root);
    for(int i=0; i < res.size(); i++)
        cout<<res.at(i)<<" ";
    cout<<endl;
    return 0;
}