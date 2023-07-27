#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xors=0,ans=0;
	for(int i=0;i<n;i++){
		xors=xors^(i+1);
		ans=ans^(arr[i]);
	}
	int axorb= xors^ans;
	int bin1=0,bin2=0,mask=1;
	while(axorb){
		if(axorb&1) break;
		else{
			axorb>>=1;
			mask<<=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(mask&i) bin1^=i;
		else bin2^=i;
		if(arr[i-1]&mask) bin1^=arr[i-1];
		else bin2^=arr[i-1];
	}

    for(int i=0;i<n;i++){
		if(arr[i]==bin1){
			swap(bin1,bin2);
			break;
		}
	}

	return {bin1,bin2};
}
