#include <bits/stdc++.h> 

bool ispossible(vector<int>positions,int n, int c,int gap){
	int prev=positions[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(positions[i]-prev>=gap) {
			prev=positions[i];
			cnt++;
		}
	}
	return cnt>=c;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int lowf=1;int highf=positions[n-1];
	while(lowf<=highf){
		// cout<<lowf<<" "<<highf<<endl;
		int focus=(lowf+highf)/2;
		if(ispossible(positions,n,c,focus)) lowf=focus+1;
		else highf=focus-1;
	}
	return highf;
}