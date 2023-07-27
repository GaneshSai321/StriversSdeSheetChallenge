#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<int>ans(vertices,INT_MAX);
    ans[source] =0;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>>pq; // node 

    //create an adjacency matrix.
    vector<vector<pair<int,int>>>adj(vertices);
    for(auto edge : vec){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});

    }

    pq.push({0,0});

    while(!pq.empty()){
        //go through each node 
        auto top = pq.top();pq.pop();
        for(auto frnd: adj[top.second]){
            if(ans[frnd.first]>top.first+frnd.second){
            ans[frnd.first] = top.first+frnd.second;
            pq.push({ans[frnd.first],frnd.first});
            }
        }
    }

    return ans;

}
