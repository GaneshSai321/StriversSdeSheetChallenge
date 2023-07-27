int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>dp(n,0);
	dp[0] = price[0];
	for(int i =1;i<n;i++){
		dp[i] = price[i];
		for(int j=0;j<i;j++){
			dp[i] = max(dp[i],dp[j]+price[i-j-1]);
		}
	}
	return dp[n-1];
}
