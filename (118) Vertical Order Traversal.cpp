#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int>ans;
    //pair consists of vertical dis and level. 
    map<pair<int,int>,vector<int>>mp;
    queue<pair<TreeNode<int>*,pair<int,int>>>q;
    if(root) q.push({root,{0,0}});
    while(!q.empty()){
        int lev=q.front().second.second;
        int v_dis=q.front().second.first;
        TreeNode<int>* temp=q.front().first;
        q.pop();
        mp[{v_dis,lev}].push_back(temp->data);
        if(temp->left) q.push({temp->left,{v_dis-1,lev+1}});
        if(temp->right) q.push({temp->right,{v_dis+1,lev+1}});
    }
    for(auto it:mp){
        for(auto ele:it.second) ans.push_back(ele);
    }
    return ans;
}