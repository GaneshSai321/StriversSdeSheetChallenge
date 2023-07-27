#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.

    int targetInd=-1;
    for(int i=n-2;i>=0;i--){
      if (permutation[i] < permutation[i + 1]) {
        targetInd = i;
        break;
      }
    }
    if(targetInd!=-1){
        for(int i=n-1;i>=0;i--){
        if(permutation[i]>permutation[targetInd])
         {
             swap(permutation[i],permutation[targetInd]);
             break;
         }
    }
    }
    

    reverse(permutation.begin()+targetInd+1,permutation.end());
    return permutation;
}