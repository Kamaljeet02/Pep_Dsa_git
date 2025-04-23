#include<iostream>
#include<cmath>
#include<map>

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

    
// LEVEL ORDER Traversal   
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        vector<int>level;
        for(int i=0; i<n; i++){
            TreeNode* node =q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
} 

// Zig zag Level order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int level=1;
    while(!q.empty()){
        vector<int> levelNode(q.size());
        
        
        int n = q.size();
        
        if(level%2 !=0){
            for(int i=0;i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                levelNode[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
        }    
        else{
            for(int i=n - 1;i >= 0 ; i--){
                TreeNode* node = q.front();
                q.pop();
                levelNode[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
        }
        level++;    
        ans.push_back(levelNode);    
    }
    return ans;
}

// Vertical Order Traversal
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    map<int, map<int, multiset<int>> >nodes;
    queue< pair< TreeNode* , pair< int,int>> >todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p =todo.front();
        todo.pop();
        TreeNode* node = p.first;
        int v = p.second.first;
        int l =p.second.second;
        nodes[v][l].insert(node->val);
        if(node->left) todo.push({node->left ,{v-1,l+1}});
        if(node->right) todo.push({node->right ,{v+1,l+1}});
        

    }
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}