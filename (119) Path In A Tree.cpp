#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool solve(vector<int>&path,TreeNode<int>* root, int x){

	if(root==0) return false;
	path.push_back(root->data);
	if(root->data==x) return true;
	
	bool found=false;

	if(root->left){
		found=found || solve(path,root->left,x);
		}

	if(root->right){
		found=found || solve(path,root->right,x);
		}

	if(found) return true;
	else path.pop_back();

	return false;
}


vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>path;
	
	solve(path,root,x);
	return path;
}
