#include <bits/stdc++.h> 

bool is_palindrome(string s, int l ,int r){
   while(l<=r){
       if(s[l++]!=s[r--]) return false;
   }
    return true;
}

void solve(vector<vector<string>>&ans,string&s,int n,int l, int r,vector<string>&partition){
    if(l==n){
        ans.push_back(partition);
        return;
    }

    for( int i=l;i<=r;i++){
        //substring from l to i
        if(is_palindrome(s,l,i)){
            // cout<<l<<" "<<i<<" "<<r<<endl;
            partition.push_back(s.substr(l,i-l+1));
            solve(ans,s,n,i+1,r,partition);
            partition.pop_back();
        }
    }

}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    int n=s.length();
    vector<vector<string>>ans;
    vector<string>partition;
    solve(ans,s,n,0,n-1,partition);
    return ans;
}