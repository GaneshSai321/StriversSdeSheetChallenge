int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int ans=0;
	int low=0,high=arr.size()-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		//mid is even
		if(mid%2==0){
			if(arr[mid]==arr[mid+1]) low=mid+1;
			else high=mid-1;
		}
		else{  //mid is odd
			if(arr[mid]==arr[mid+1]) high=mid-1;
			else low=mid+1;
		}
	}

	return arr[low];
}