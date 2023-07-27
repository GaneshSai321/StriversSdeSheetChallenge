#include <bits/stdc++.h>


void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>a,int n,int k,int ind){


    if(ind==n) {
        if(k==0&&temp.size()!=0){
        ans.push_back(temp);
    }
        return;
    }
        

    //not pick
    solve(ans,temp,a,n,k,ind+1);

    //pick that index
    temp.push_back(a[ind]);

    solve(ans,temp,a,n,k-a[ind],ind+1);
    
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;

    solve(ans,temp,arr,n,k,0);

    return ans;
}