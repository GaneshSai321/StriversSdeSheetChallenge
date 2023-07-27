#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    queue<TreeNode<int>*>q;
    q.push(root);
    if(root==0) return 0;
    int maxlen=0;
    while(!q.empty()){
        int s= q.size();
        maxlen=max(maxlen,s);
        for(int i=0;i<s;i++){
            TreeNode<int>*temp=q.front();q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return maxlen;
}