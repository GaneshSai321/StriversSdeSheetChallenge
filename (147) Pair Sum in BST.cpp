#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/


class BSTiterator
{
    stack<BinaryTreeNode<int>*>st;
    public:
    BSTiterator(BinaryTreeNode<int> *root)
    {
        // write your code here
        while(root){
            st.push(root);
            root=root->left;
        }
    }

    BinaryTreeNode<int>* next()
    {
        // write your code here
        BinaryTreeNode<int>* temp = st.top();
        BinaryTreeNode<int>* num = temp;
        st.pop();
        temp = temp ->right;
        while(temp) {
            st.push(temp);
            temp =temp->left;
        }
        return num;
        
    }

    bool hasNext()
    {
        // write your code here
        return (!st.empty());
    }
};


class RBSTiterator
{
    stack<BinaryTreeNode<int>*>st;
    public:
    RBSTiterator(BinaryTreeNode<int> *root)
    {
        // write your code here
        while(root){
            st.push(root);
            root=root->right;
        }
    }

    BinaryTreeNode<int>* next()
    {
        // write your code here
        BinaryTreeNode<int>* temp = st.top();
        BinaryTreeNode<int>* num = temp;
        st.pop();
        temp = temp ->left;
        while(temp) {
            st.push(temp);
            temp =temp->right;
        }
        return num;
    }

    bool hasNext()
    {
        // write your code here
        return (!st.empty());
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/




bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator it(root);
    RBSTiterator rit(root);
    BinaryTreeNode<int>* num1= it.next(),*num2=rit.next();
    while(num1!=num2 && num1->data<=num2->data){
        if(num1->data+num2->data==k) return true;
        if(num1->data+num2->data>k) num2=rit.next();
        if(num1->data+num2->data<k) num1 = it.next();
    }
    return false;
}