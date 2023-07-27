#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n= arr.size();
    unordered_map<int,int>mp;
    int cnt=0;
    int exor=0;
    for(int i=0;i<n;i++){
       exor^=arr[i];
       if(mp.find(exor^x)!=mp.end()) cnt+=mp[exor^x];
       if(exor==x)cnt++;
       mp[exor]++;
    }
    return cnt;
}