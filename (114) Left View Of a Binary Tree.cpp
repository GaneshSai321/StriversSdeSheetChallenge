#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void f(vector<int>&ans,TreeNode<int>*root,int level){
    if(root==0) return;

    if(level==ans.size()) ans.push_back(root->data);
    if(root->left) f(ans,root->left,level+1);
    if(root->right) f(ans,root->right,level+1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    f(ans,root,0);
    return ans;

}