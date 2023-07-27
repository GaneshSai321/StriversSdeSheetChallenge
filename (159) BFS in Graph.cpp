#include <bits/stdc++.h> 
vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>>adj(v);
    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    for(int i=0;i<v;i++) sort(adj[i].begin(),adj[i].end());

    vector<int>bfs;
    queue<int>q;
    vector<bool>vis(v,false);
    for(int i =0;i<v;i++){
        if(!vis[i]) q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int cur = q.front();
            bfs.push_back(cur);
            q.pop();
            for(auto x:adj[cur]){
                if(!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                }
            }
        }
    }
    return bfs;
}