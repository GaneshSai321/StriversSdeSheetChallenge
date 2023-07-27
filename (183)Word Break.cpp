#include <bits/stdc++.h> 

bool solve(int ind,string &target,set<string>&dict,vector<int>&dp){
    if(ind == target.size()) return true;
        string word = "";
    if(dp[ind]!=-1) return dp[ind];
    for(int j =ind;j<target.size();j++){
        word+=target[j];
        if(dict.find(word)!=dict.end()){
          if (solve(j + 1, target, dict,dp)) {
            dp[ind] = true;
            return true;
          }
        }
    }
    dp[ind] = false;
    return false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    set<string>dict;
    vector<int>dp(target.size(),-1);
    for(auto i : arr) dict.insert(i);
    return solve(0,target,dict,dp);
}