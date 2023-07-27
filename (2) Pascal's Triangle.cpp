#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
   vector<long long int> temp;
   temp.push_back(1);
   ans.push_back(temp);
   for(int i=0;i<n-1;i++){
     vector<long long int>v;
     v.push_back(1);
     for(int j=0;j<i;j++){
       v.push_back(ans[i][j]+ans[i][j+1]);
     }
     v.push_back(1);
     ans.push_back(v);
   }
   return ans;
}
