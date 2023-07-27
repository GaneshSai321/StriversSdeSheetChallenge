#include <bits/stdc++.h> 

int solve(int i, int j, int m, int n,vector<vector<int>>&dp){
	if(i==m-1&&j==n-2) return 1;
	if(i==m-2&&j==n-1) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans=0;
	if(i!=m-1) ans+=solve(i+1,j,m,n,dp);
	if(j!=n-1) ans+=solve(i,j+1,m,n,dp);
	dp[i][j]=ans;
	return ans;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	if(m==1&&n==1) return 1;
    vector<vector<int>>dp(m,vector<int>(n,-1));
	return solve(0,0,m,n,dp);
}