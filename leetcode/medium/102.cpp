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
        // vector<vector<int>> levelOrder(TreeNode* root) {
        //     if(!root)
        //         return {};

        //     queue<TreeNode*> q;
        //     vector<vector<int>> res;

        //     q.push(root);
            
        //     while(!q.empty()){
        //         vector<int> lvl;
        //         queue<TreeNode*> intermq;
        //         while(q.size()>0){
        //             lvl.push_back(q.front()->val);
        //             intermq.push(q.front());
        //             q.pop();
        //         }
        //         res.push_back(lvl);
        //         while(intermq.size()>0){
        //             if(intermq.front()->left)
        //                 q.push(intermq.front()->left);
        //             if(intermq.front()->right)
        //                 q.push(intermq.front()->right);
        //             intermq.pop();
        //         }
        //     }
        //     return res;
        // }


        // map<int, vector<int>> lvls;

        // void dfs(TreeNode* root, int depth){
        //     if(root){
        //         dfs(root->left, depth+1);
        //         this->lvls[depth].push_back(root->val);
        //         dfs(root->right, depth+1);
        //     }
        // }

        // vector<vector<int>> levelOrder(TreeNode* root) {
        //     if(!root)
        //         return {};
        //     dfs(root, 0);
        //     vector<vector<int>> res;
        //     for(auto e : this->lvls)
        //         res.push_back(e.second);
        //     return res;
        // }


        vector<vector<int>> levelOrder(TreeNode* root){
            if(!root)
                return {};

            vector<vector<int>> res;
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()){
                vector<int> lvl;
                int lenghtQueue = q.size();
                while(lenghtQueue){
                    TreeNode* front = q.front();
                    lvl.push_back(front->val);
                    q.pop();
                    lenghtQueue--;
                    if(front->left)
                        q.push(front->left);
                    if(front->right)
                        q.push(front->right);
                }
                res.push_back(lvl);
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
    
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
        
    Solution sol;

    vector<vector<int>> res = sol.levelOrder(root);
    cout<<res.size()<<endl;
    for(int i = 0; i < res.size(); i++){
        cout<<"level: "<<i<<endl;
        for(int node : res[i])
            cout<<"node:  "<<node<<" ";
        cout<<endl;
    }

    return 0;
}