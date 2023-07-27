#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int K) {
	// Write your code here.
	vector<vector<int>>ans;
         sort(nums.begin(),nums.end());
         int i=0;
         while(i<n){
             int first=nums[i];
             int left=i+1,right=n-1;
             while(left<right){
                 if(nums[left]+nums[right]+first<K){
                     left++;
                 }
                 else if(nums[left]+nums[right]+first>K){
                     right--;
                 }
                 else{
                     ans.push_back({first,nums[left],nums[right]});
                     while(left!=n-1&&nums[left+1]==nums[left])left++;
                     while(right!=0&&nums[right-1]==nums[right])right--;
                     left++;right--;
                 }
             }
             while(i<n-1&&nums[i+1]==nums[i]) i++;
             i++;
         }
         return ans;
}