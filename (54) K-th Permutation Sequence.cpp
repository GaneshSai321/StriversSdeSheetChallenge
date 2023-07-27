#include <bits/stdc++.h>

string kthPermutation(int n, int k) {
    // Write your code here.
   
   string s="",ans="";
   int fact=1;
   for(int i=1;i<=n;i++){
       s+=('0'+i);
       fact*=i;
   }
   k--;  //for zero indexing...
   while(true){
       
       int len= s.length();
       if(len==0) break;
       int grp_size=fact/len;
       int grp=k/grp_size;
       ans+=s[grp];
       s.erase(s.begin()+grp);
       k=k%grp_size;
       fact/=len;
   }
    return ans;
}
