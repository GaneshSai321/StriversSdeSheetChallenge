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
pair<bool,int> isbal(BinaryTreeNode<int>* root ){
    if(root == 0) return {true,0};

    auto lpair = isbal(root->left);
    auto rpair = isbal(root->right);

    if(lpair.first && rpair.first && abs(lpair.second-rpair.second)<=1) return {true,1+max(lpair.second,rpair.second)};
    else return {false,-1};

}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return isbal(root).first;
    
}