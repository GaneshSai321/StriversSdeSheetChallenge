#include <bits/stdc++.h> 

vector<int>merge(vector<int>a,vector<int>b){
    int len1=a.size(),len2=b.size(),ptr1=0,ptr2=0;
    vector<int>res;
    while(ptr1<len1&&ptr2<len2){
        if(a[ptr1]<=b[ptr2]) res.push_back(a[ptr1++]);
        else res.push_back(b[ptr2++]);
    } 
    while(ptr1<len1) res.push_back(a[ptr1++]);
    while(ptr2<len2) res.push_back(b[ptr2++]);
    return res;
}

void solve(vector<vector<int>>&arr,int k,int ind){
    if(ind==k-1) return;
    solve(arr,k,ind+1);
    arr[ind]=merge(arr[ind],arr[ind+1]); 
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    solve(kArrays,k,0);
    return kArrays[0];

}
