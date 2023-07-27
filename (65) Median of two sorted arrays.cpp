double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	int n1=a.size(),n2=b.size();
	int psize=(n1+n2)/2;

	int low=0;
	int high=n1;
	while(low<=high){
		int cut1=low+(high-low)/2;
		int cut2= psize-cut1;
		int l1= cut1==0?0:a[cut1-1];
		int l2= cut2==0?0:b[cut2-1];
		int r1= cut1==n1?INT_MAX:a[cut1];
		int r2= cut2==n2?INT_MAX:b[cut2];

		if(l1<=r2&&l2<=r1){
			if((n1+n2)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
			else return min(r1,r2)*1.0;
		}
		if(l1>r2){
			high=cut1-1;
		}
		else low=cut1+1;
	}
	return 0.0;
}