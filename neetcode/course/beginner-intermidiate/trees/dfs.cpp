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
    int nbNodes = 0;

    void inorderTraversal(TreeNode* root){
        if(root){
            inorderTraversal(root->left);
            cout<<root->val<<" ";
            inorderTraversal(root->right);
        }
    }

    void reverseOrderTraversal(TreeNode* root){
        if(root){
            reverseOrderTraversal(root->right);
            cout<<root->val<<" ";
            reverseOrderTraversal(root->left);
        }
    }

    void preorderTraversal(TreeNode* root){
        if(root){
            cout<<root->val<<" ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode* root){
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout<<root->val<<" ";
        }
    }

    int countNodes(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
    
        int nl = countNodes(root->left);
        int nr = countNodes(root->right);

        return 1 + nr + nl;
    }

    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
    
        int hl = countDepth(root->left);
        int hr = countDepth(root->right);

        if(hr > hl){
            return 1 + hr;
        }
        
        return 1 + hl;
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
    
    // cout<<"Inorder"<<endl;
    // sol.inorderTraversal(root); // 1 2 3 4 5 6
    // cout<<endl;
    // cout<<"Reverseorder"<<endl;
    // sol.reverseOrderTraversal(root); // 6 5 4 3 2 1
    // cout<<endl;
    // cout<<"Preorder"<<endl;
    // sol.preorderTraversal(root); // 5 3 2 1 4 6
    // cout<<endl;
    // cout<<"Postorder"<<endl;
    // sol.postorderTraversal(root); // 1 2 4 3 6 5
    // cout<<endl;
    // int* n = nullptr;
    // n = 0;

    int count = sol.countNodes(root);
    int height = sol.countDepth(root);
    cout<<"Number of nodes: "<<count<<endl;
    cout<<"Depth of the tree: "<<height<<endl;
    return 0;
}