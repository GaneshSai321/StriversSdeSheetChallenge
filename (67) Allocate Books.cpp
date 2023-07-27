#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
   long long s = 0;

    int maxTime = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        s += time[i];
        maxTime = max(maxTime , time[i]);
    }


	long long mini=maxTime,maxi=s;

	while(mini<=maxi){
		long long mid=(mini+maxi)/2;
		
		long long cnt=1,sum=0;
		for(int i=0;i<m;i++){
			
			sum+=time[i];
			if(sum>mid) {
				cnt++;
				sum=time[i];
			}
		}
		if(cnt>n) mini=mid+1;
		else maxi=mid-1;
	}
	return mini;
}