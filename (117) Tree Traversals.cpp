#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>ans(3);
    stack<pair<BinaryTreeNode<int>*,int>>st;
    if(root) st.push({root,0});
    while(!st.empty()){
        auto temp = st.top();st.pop();
        if(temp.second==0){
            //preorder
            ans[1].push_back(temp.first->data);
            st.push({temp.first,temp.second+1});
            if(temp.first->left) st.push({temp.first->left,0});
        }
        else if(temp.second==1){
            //inorder
            ans[0].push_back(temp.first->data);
            st.push({temp.first,temp.second+1});
            if(temp.first->right) st.push({temp.first->right,0});
        }
        else{
            //postorder
            ans[2].push_back(temp.first->data);
        }
    }
    return ans;
}