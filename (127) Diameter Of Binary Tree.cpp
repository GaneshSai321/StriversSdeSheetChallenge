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

int h(TreeNode<int>* root,int &mans){
    if(root==0) return 0;
    if(root->left==0&&root->right==0) return 0;
    int lh=0,rh=0;
    if(root->left) lh = 1+h(root->left,mans);
    if(root->right) rh = 1+h(root->right,mans);
    mans=max(mans,lh+rh);
    return max(lh,rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
   int mans=0;
    if(root==0) return 0;
    h(root,mans);
    return mans;
    
}
