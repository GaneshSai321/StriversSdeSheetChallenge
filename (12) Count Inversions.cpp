#include <bits/stdc++.h> 
long long cnt=0;

void merge(long long *nums,int low,int high){
        int mid=(low+high)/2;
        vector<long long >a(nums+low,nums+mid+1),b(nums+mid+1,nums+high+1);
        int ptr1=0,ptr2=0,ptr=low,len1=mid-low+1,len2=high-mid;
        // show(a);
        // show(b);
       
         
        while(ptr1!=len1&&ptr2!=len2){
            if(a[ptr1]<=b[ptr2]) nums[ptr++]=a[ptr1++];
            else {
                // cout<<low<<" "<<high<<" "<<mid<<" "<<ptr1<<endl;
              nums[ptr++] = b[ptr2++];
                cnt+=mid-low+1-ptr1;
            }
        }

        while(ptr1!=len1) nums[ptr++]=a[ptr1++];
        while(ptr2!=len2) nums[ptr++]=b[ptr2++];
        //  cout<<low<<" "<<high<<" "<<cnt<<"...\n";
    }

    void mergeSort(long long *nums,int low,int high){
        if(low>=high) return;
        int mid= (low+high)/2;
        //apply mergesort on left part
        mergeSort(nums,low,mid);
        //apply mergesort on right part
        mergeSort(nums,mid+1,high);

        //merge both the parts...

        merge(nums,low,high);
    }

long long getInversions(long long *arr, int n){
    cnt=0;
    // Write your code here.
      mergeSort(arr,0,n-1);
    //   for(int i=0;i<n;i++)cout<<arr[i]<<"..";
      cout<<endl;
      return cnt;
}







