#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>mp;
    map<int,vector<int>>rmp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it:mp){
        rmp[it.second].push_back(it.first);
    }
    vector<int>ans;
    for (auto it = rmp.rbegin(); it != rmp.rend(); it++){
        vector<int> v= it->second;
        for(auto ele: v) {
            ans.push_back(ele);
            if(ans.size()==k) {
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
    }

}