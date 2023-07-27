#include <bits/stdc++.h> 

void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>v,int ind){
    if(ind==v.size()){
        ans.push_back(temp);
        return;
    }
    solve(ans,temp,v,ind+1);
    temp.push_back(v[ind]);
    solve(ans,temp,v,ind+1);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>ans;
    vector<int>temp;
    sort(v.begin(),v.end());
    solve(ans,temp,v,0);
    return ans;

}