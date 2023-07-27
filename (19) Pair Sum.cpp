#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   int n= arr.size();
    unordered_map<int,int>mp;
   vector<vector<int>>ans;
   for(int i=0;i<n;i++){

      int ele=arr[i];
      if(mp.find(s-ele)!=mp.end()) {
         int cnt=mp[s-ele];
         vector<int> v;
         v.push_back(ele);
         v.push_back(s-ele);
         sort(v.begin(),v.end());
         for(int j=0;j<cnt;j++) ans.push_back(v);
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}