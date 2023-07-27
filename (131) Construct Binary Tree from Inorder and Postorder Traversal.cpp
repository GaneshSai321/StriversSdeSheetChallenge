/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 #include <bits/stdc++.h>

 TreeNode<int>* buildTree(vector<int>&postOrder,vector<int>&inOrder,int inleft,int inright, int postleft,int postright,map<int,int>&inmap){
      if(inleft>inright) return 0;
     //  cout<<inleft<<" ... "<<inright<<" ---> "<<postleft<<"... "<<postright<<endl;
      if(inleft == inright) return new TreeNode<int>(inOrder[inleft]);

      int rootele = postOrder[postright];
      int rootind = inmap[rootele];
      TreeNode<int>* root = new TreeNode<int>(rootele);
      int postRighteles = inright-rootind;
      int postLefteles = rootind - inleft;
      root->left = buildTree(postOrder, inOrder, inleft, rootind-1,  postright-postLefteles-postRighteles,  postright-postRighteles-1,inmap);
      root->right = buildTree(postOrder, inOrder, rootind+1, inright,  postright-postRighteles,  postright-1,inmap);
      return root;
 }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     map<int,int>inmap;
     for(int i=0;i<inOrder.size();i++){
          inmap[inOrder[i]] = i;
     }
     return buildTree(postOrder,inOrder,0,inOrder.size()-1,0,postOrder.size()-1,inmap);
}
