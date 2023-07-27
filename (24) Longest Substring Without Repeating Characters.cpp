#include <bits/stdc++.h> 
int uniqueSubstrings(string a)
{
    //Write your code here
    unordered_map<char,int>mp;
    int maxlen=0,n=a.length();
    int left=0,right=0;
    while(left<n&&right<n){
        mp[a[right]]++;
        if(mp[a[right]]>1){
            
            while(a[left]!=a[right]){

                mp[a[left]]--;
                left++;
            } 
            left++;
            mp[a[right]]=1;
        }
        maxlen=max(maxlen,right-left+1);
         right++;
    }

    return maxlen;

}
