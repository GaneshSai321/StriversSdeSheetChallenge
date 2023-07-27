#include <bits/stdc++.h> 

string solve(string a){
	string ans = "";
	char ch = a[0];
	int cnt =1;
	int n = a.length();
	for(int i = 1;i<n;i++){
		if(a[i]==ch) cnt++;
		else{
			ans+=to_string(cnt);
			ans+=ch;
			cnt =1;
			ch = a[i];
		}
	}
	ans+=to_string(cnt);
	ans+=ch;
	return ans;
}


string writeAsYouSpeak(int n) 
{
	// Write your code here.
	string ans = "1";
	for(int i =0;i<n-1;i++){
		// cout<<ans<<endl;
		ans = solve(ans);
	}	
	return ans;
}