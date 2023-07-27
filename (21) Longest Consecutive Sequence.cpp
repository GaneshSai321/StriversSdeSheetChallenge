#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    set<int>st(arr.begin(),arr.end());
    int prev=INT_MIN,cnt=0,ans=0;
    for(auto it: st){
        if(it-1!=prev){
            ans=max(ans,cnt);
            cnt=1;
        }
        else cnt++;
        prev=it;
    }
    ans=max(ans,cnt);
    
    return ans;
}