#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	 vector<int>com;
	 for(int i=0;i<n;i++) 
		 for(int j=0;j<n;j++)
		 	com.push_back(a[i]+b[j]);
	 
	 sort(com.begin(),com.end());
	vector<int>res(com.begin()+n*n-k,com.end());
	reverse(res.begin(),res.end());
	return res;
}