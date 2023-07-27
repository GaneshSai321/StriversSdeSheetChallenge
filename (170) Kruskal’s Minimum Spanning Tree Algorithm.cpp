#include <bits/stdc++.h> 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<bool>vis(n+1,false);
	vector<vector<pair<int,int>>>adj(n+1);
    int ans =0;
    for(auto edge: graph){
        int a = edge[0];
        int b = edge[1];
        int wt = edge[2];
        adj[a].push_back({b,wt});
		adj[b].push_back({a,wt});
    }

	pq.push({0,{1,1}});
    while(!pq.empty()){
        auto edge = pq.top();pq.pop();
        int a = edge.second.first;
        int b = edge.second.second;
        int wt = edge.first;
		 if(!vis[a] || !vis[b]) ans+=wt;
        if(!vis[a]) {
			vis[a] =true;
			for(auto frnd:adj[a]){
				if(!vis[frnd.first]) pq.push({frnd.second,{a,frnd.first}});
			}
		}
		if(!vis[b]){
			vis[b] =true;
			for(auto frnd:adj[b]){
				if(!vis[frnd.first]) pq.push({frnd.second,{b,frnd.first}});
			}
		}
    }
    
    return ans;
}