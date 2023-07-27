#include<bits/stdc++.h>

bool is_valid(int i ,int j, int n, int m , vector<vector<int>>&grid){
    return i>=0&&j>=0&&i<n&&j<m&&grid[i][j]==1;
}




int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    queue<pair<pair<int,int>,int>>q;
    int freshcnt=0;

    int maxtime=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2) q.push({{i,j},0});
            if(grid[i][j]==1) freshcnt++;
        }
    }

    while(!q.empty()){
        auto pr = q.front();
        int i = pr.first.first;
        int j = pr.first.second;
        int time = pr.second;
        maxtime=max(maxtime,time);
        q.pop();
        if(is_valid(i, j-1 , n, m, grid)) {
            grid[i][j-1] = 2;
            freshcnt--;
            q.push({{i,j-1},time+1});
        }
        if(is_valid(i, j+1 , n, m, grid)){
            grid[i][j+1] = 2;
            freshcnt--;
            q.push({{i,j+1},time+1});
        }
        if(is_valid(i-1, j , n, m, grid)){
            grid[i-1][j] = 2;
            freshcnt--;
            q.push({{i-1,j},time+1});
        }
        if(is_valid(i+1, j , n, m, grid)){
            grid[i+1][j] = 2;
            freshcnt--;
            q.push({{i+1,j},time+1});
        }
    }
    if(freshcnt>0) return -1;
return maxtime;

}