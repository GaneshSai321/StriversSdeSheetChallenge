#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
     vector<vector<int>>ans;
         sort(nums.begin(),nums.end());
         int i=0,j;
         while(i<n){
             j=i+1;
             while(j<n){
                 int first=nums[i];
                 int second=nums[j];
             int left=j+1,right=n-1;
             while(left<right){
                 if(nums[left]+nums[right]+first+second<target){
                     left++;
                 }
                 else if(nums[left]+nums[right]+first+second>target){
                     right--;
                 }
                 else{
                     ans.push_back({first,second,nums[left],nums[right]});
                     while(left!=n-1&&nums[left+1]==nums[left])left++;
                     while(right!=0&&nums[right-1]==nums[right])right--;
                     left++;right--;
                 }
             }
             while(j<n-1&&nums[j+1]==nums[j]) j++;
             j++;
             
             }
             while(i<n-1&&nums[i+1]==nums[i]) i++;
             i++;
         }
         if(ans.size()) return "Yes";
         else return "No";
}
