#include <bits/stdc++.h>


int solve(vector<int>roots,vector<int>&inorder, int pos[]){
	int cnt =0;
	for(auto root: roots){
		int ind =-1, n=inorder.size();
		ind = pos[root];
		// for(int i =0;i<n;i++) if(inorder[i]==root) ind =i;
		inorder[ind] =-1;
		if(ind!=0 && inorder[ind-1]!=-1) cnt++;
		if(ind!=n-1 && inorder[ind+1]!=-1) cnt++;
	}
	return cnt;
}
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
	int ht=0;
	int j =0 , len = 1, n= levelOrder.size();
	int pos[n+1];
	for(int i=0;i<n;i++){
		pos[inorder[i]] = i;
	}
	while(j<n){
		ht++;
		vector<int>roots;
		for(int i=j;i<j+len;i++) roots.push_back(levelOrder[i]);
		j+=len;
		len = solve(roots,inorder,pos);
		if(len==0) break;
	}
    return ht-1;
}