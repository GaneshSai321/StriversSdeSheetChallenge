#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long value(TreeNode<int>*root,long long &ans){
    if(root==0) return 0;
    long long lval = 0 , rval = 0;
    if(root->left) lval = value(root->left,ans);
    if(root->right) rval = value(root ->right,ans);
    ans = max(ans, lval + rval + root->val);
    return max(lval,rval)+root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root || root->left==0 || root->right==0) return -1;
    long long ans = 0;
    value(root,ans);
    return ans;
}