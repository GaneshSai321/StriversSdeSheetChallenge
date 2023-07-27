#include<bits/stdc++.h>

long solve(int*denominations,int ind,int n,int value,vector<vector<long>>&dp){
    if(ind==n){
        if(value==0) return 1;
        return 0;
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    long ans =0;
    int max_of_this_type = value/denominations[ind];
    for(int i =0;i<=max_of_this_type;i++){
        ans+=solve(denominations,ind+1,n,value-i*denominations[ind],dp);
    }
    dp[ind][value] = ans;
    return ans;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return solve(denominations,0,n,value,dp);

}