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

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==0) return 0;
    if(root->left==0 && root->right==0) return root;
    BinaryTreeNode<int>* temp = root;
    if(root->left) {
    BinaryTreeNode<int>* left = BTtoDLL(root->left);  
    temp = left;
    while(left->right!=0) left = left->right;
    left->right = root;
    root->left = left;  
    }
    if(root->right) {
    BinaryTreeNode<int>* right = BTtoDLL(root->right);  
    root->right = right;  
    right->left = root;
    }
    return temp;
}