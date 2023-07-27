#include <bits/stdc++.h> 

bool is_palindrome(string s){
    int n =s.length();
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}

int solve(int ind,string &str,int n,vector<int>&dp){
    if(ind==n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int mini=n;
    int j =ind;
    string s="";
    while(j<n){
        s+=str[j];
        if (is_palindrome(s)) {
            int ways = solve(j+1,str,n,dp);
            int add = j==n-1?0:1;
            mini = min(mini,add+ways);
        }
        j++;
    }
    dp[ind] = mini;
    return mini;
}


int palindromePartitioning(string str) {
    // Write your code here
    vector<int> dp(str.length(),-1);
    return solve(0,str,str.length(),dp);
}


