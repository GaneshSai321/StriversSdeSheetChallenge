#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int ele=arr[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(arr[i]==ele) cnt++;
		else cnt--;
		if(cnt==0){
			ele=arr[i];
			cnt=1;
		} 
	}

	int freq=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ele){
			freq++;
		}
	}
	if(freq<=n/2) return -1;
	return ele;
}