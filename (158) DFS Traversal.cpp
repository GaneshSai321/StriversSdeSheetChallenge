vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>adj(v);
    for(int i =0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool>vis(v,false);
    stack<int>st;
    vector<vector<int>>dfs;
    // dfs.push_back({0});
    for(int i=0;i<v;i++){
        vector<int>temp;
        if(!vis[i]) {
        // dfs[0][0]++;
            st.push(i);
            vis[i]=true;
            while(!st.empty()){
                int ele = st.top();
                st.pop();
                temp.push_back(ele);
                for(auto x:adj[ele]){
                    if(!vis[x]) {
                        vis[x]= true;
                        st.push(x);
                    }
                }
            }
        sort(temp.begin(),temp.end());
        dfs.push_back(temp);
        }
    }
    return dfs;
}