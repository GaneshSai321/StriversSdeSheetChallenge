#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int ptr2=n-1;
   int ptr0=0;
   
   
   
   for(int i=0;i<n;i++){
      if(i>ptr2) break;
      if(arr[i]==0){
         swap(arr[i],arr[ptr0]);
         ptr0++;
      }
      else if (arr[i]==2){
         swap(arr[i],arr[ptr2]);
         i--;
         ptr2--;
      }
   }
   
}