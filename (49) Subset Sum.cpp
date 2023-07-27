#include <bits/stdc++.h> 

void solve(vector<int>&ans,vector<int>num,int ind,int sum){
    if(ind==num.size()){
        ans.push_back(sum);
        return;
    }

    //not pick case
    solve(ans,num,ind+1,sum);

    //pick case
    solve(ans,num,ind+1,sum+num[ind]);

}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    solve(ans,num,0,0);
    sort(ans.begin(),ans.end());
    return ans;
}