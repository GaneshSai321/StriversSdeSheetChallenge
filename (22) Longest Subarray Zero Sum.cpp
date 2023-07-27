#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  unordered_map<int,int>prefix;
  int sum=0,maxlength=0;

  for(int i=0;i<arr.size();i++){
    sum+=arr[i];

    if(sum==0) maxlength= i+1;

    else if(prefix.find(sum)!=prefix.end()){
      maxlength=max(maxlength,i-prefix[sum]);
    }

    else prefix[sum]=i;
  }

  return maxlength;
}