#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;

    int order=0;
    queue<BinaryTreeNode<int>*>q;
    if(root)
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        
        vector<int>v(n);
        for(int i=0;i<n;i++){
            int ind=i;
            if(order) ind=n-i-1;
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            v[ind]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        for(int i=0;i<n;i++) ans.push_back(v[i]);
        order^=1;
    }
    return ans;
}
