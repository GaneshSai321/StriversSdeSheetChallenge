#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    int n = arr.size();
    map<int,int>mp;
    int i =0,j=0;
    vector<int>ans;
    while(j<n){
        mp[arr[j]]++;
        if(j>=k){
            mp[arr[i]]--;
            if(mp[arr[i]]==0) mp.erase(arr[i]);
            i++;
        }
        if(j>=k-1)
        ans.push_back(mp.size());
        j++;
    }
	return ans;
}
