#include <bits/stdc++.h>

void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>arr,int n,int ind ,int target){
	
		if(target==0) ans.push_back(temp);
		
	


	for(int i=ind;i<n;i++){
		if(i!=ind&&arr[i]==arr[i-1]) continue;
		
		if(target>=arr[i]) {
			temp.push_back(arr[i]);
			solve(ans,temp,arr,n,i+1,target-arr[i]);
			temp.pop_back();
		}

	}
	
	
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.

	sort(arr.begin(),arr.end());
	vector<int>temp;
	vector<vector<int>>ans;
	solve(ans,temp,arr,n,0,target);
	return ans;

}
