#include<iostream>
#include<cmath>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
//Using stack Root Left Right
    //We will add Right first in stack then left
    // beacause then only Left will be on top.
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            ans.push_back(node->val);
        }
        return ans;
    }