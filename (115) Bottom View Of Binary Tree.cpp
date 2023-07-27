#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<int,BinaryTreeNode<int>*>>q;
    map<int,int>mp;
    vector<int> ans;
    if(root) q.push({0,root});
    while(!q.empty()){
        BinaryTreeNode<int>*temp = q.front().second;
        int dis=q.front().first;
        q.pop();
        mp[dis]=temp->data;

        if(temp->left) q.push({dis-1,temp->left}); 
        if(temp->right) q.push({dis+1,temp->right}); 
    }
    for(auto it:mp) ans.push_back(it.second);
    return ans;
    
}
