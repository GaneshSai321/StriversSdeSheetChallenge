#include <bits/stdc++.h> 

void solve(vector<vector<int>>&ans,vector<int>temp,int ind,vector<int>arr,int n){
    ans.push_back(temp);
    for(int i=ind;i<n;i++){
        if(i!=ind&&arr[i]==arr[i-1]) continue;
        temp.push_back(arr[i]);
        solve(ans,temp,i+1,arr,n);
        temp.pop_back();
    }
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int>temp;
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    solve(ans,temp,0,arr,n);
    return ans;
}