#include <bits/stdc++.h> 

int merge(vector<int>&arr , int low ,int high , int mid){
	vector<int>a(arr.begin()+low,arr.begin()+mid+1),b(arr.begin()+mid+1,arr.begin()+high+1);
    int cnt =0;
	int l=0,r=0,len1=mid-low+1,len2=high-mid;
    
	while(l<len1){
		
		while(r<len2&&a[l]>2*b[r]) r++;
		cnt+=r;
		l++;
	}

	l=0;r=0;
	int ptr=low;

	while(l!=len1&&r!=len2){
		if(a[l]<=b[r]) arr[ptr++]=a[l++];
		else arr[ptr++]=b[r++];
	}

	while(l!=len1) arr[ptr++]=a[l++];
	while(r!=len2) arr[ptr++]=b[r++];

    // cout<<low<<" "<<high<<" "<<cnt<<endl;
	return cnt;

}



int mergeSort(vector<int> &arr, int low, int high){
	int cnt=0;
	if(low>=high) return 0;

	int mid = (low+high)/2;

	//sort the left half
	cnt+=mergeSort(arr,low,mid);

	
	//sort the right half
	cnt+=mergeSort(arr,mid+1,high);

	

	//merge both the parts
	cnt+=merge(arr,low,high,mid);

	

	return cnt;
}


int reversePairs(vector<int> &arr, int n){
	// Write your code here.

	return mergeSort(arr,0,n-1);

	 
	
	
}