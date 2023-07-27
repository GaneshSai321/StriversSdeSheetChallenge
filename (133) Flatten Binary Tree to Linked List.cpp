#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int>* getPre(TreeNode<int>*root){
    if(root->left==0 && root->right==0) return root;
    TreeNode<int>* temp = root->right, *temp2=root;
    if(root->left)
    {
        root->right = getPre(root->left);
        while(temp2->right!=0) temp2= temp2->right;
    } 
     if(temp) temp2->right = getPre(temp);
    return root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    return getPre(root);

}