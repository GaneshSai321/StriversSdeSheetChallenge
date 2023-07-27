void solve(BinaryTreeNode<int> *root, int X,int &ceil, int &tmp){

if (!root) return;

 

if (root->data == X) {

ceil = root->data;

return;

}

 

if (root->data > X) {

if (root->data < tmp) {

tmp = root->data;

ceil = root->data;

}

solve(root->left, X, ceil, tmp);

} else

solve(root->right, X, ceil, tmp);

}

 

int findCeil(BinaryTreeNode<int> *root, int X){

if(!root) return 0;

int ceil = -1 , tmp = INT_MAX;

solve(root,X,ceil,tmp);

return ceil;

}