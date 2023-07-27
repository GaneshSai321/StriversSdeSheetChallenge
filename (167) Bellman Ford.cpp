#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>ans(n+1,1e9);
    ans[src] = 0;
    for(int i=0;i<n-1;i++){

        for(auto edge: edges){
        int a = edge[0];
        int b = edge[1];
        int weight = edge[2];
        if(ans[a]!=1e9 && ans[b]>ans[a]+weight) ans[b] = ans[a]+weight;
    }
}
    
    return ans[dest];
}