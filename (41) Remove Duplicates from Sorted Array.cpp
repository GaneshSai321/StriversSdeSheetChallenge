int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int slow=1;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1]) arr[slow++]=arr[i];
	}
	return slow;
}
