#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    queue<pair<int,TreeNode<int>*>>q;
    map<int,int>mp;
    vector<int> ans;
    if(root) q.push({0,root});
    while(!q.empty()){
        TreeNode<int>*temp = q.front().second;
        int dis=q.front().first;
        q.pop();
        if(mp.find(dis)==mp.end())mp[dis]=temp->val;

        if(temp->left) q.push({dis-1,temp->left}); 
        if(temp->right) q.push({dis+1,temp->right}); 
    }
    for(auto it:mp) ans.push_back(it.second);
    return ans;

}