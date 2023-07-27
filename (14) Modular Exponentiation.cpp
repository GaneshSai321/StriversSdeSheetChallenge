#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	if(n==0) return 1;
	long long int res=modularExponentiation(x,n/2,m);
	if(n&1) return ((x%m)*((res*res)%m))%m;
	else return (res*res)%m;
}