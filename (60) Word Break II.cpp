#include <bits/stdc++.h> 

vector<string> solve(int ind,string &target,set<string>&dict,vector<vector<string>>&dp){
    if(ind == target.size()) return {""};
    if(dp[ind][0].length()!=0) return dp[ind];
    string word ="";
    vector<string>ans;
    for(int j =ind;j<target.size();j++){
        word+=target[j];

        if(dict.find(word)!=dict.end()){
            vector<string> prev = solve(j + 1, target, dict,dp);
            for(int i =0;i<prev.size();i++){
                prev[i] = word + " " +prev[i];
            }
            for(auto str:prev) ans.push_back(str);
        }
    }

    dp[ind] = ans;
    return ans;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    set<string>dict;
    vector<vector<string>>ans(s.length(),{""});
    for(auto i : dictionary) dict.insert(i);
    return solve(0, s, dict, ans);
    
}




