#include <bits/stdc++.h> 

vector<int> transform(vector<vector<bool>>v, int n){
  vector<int>temp;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      temp.push_back(v[i][j]);
  return temp;
}

bool check(int x,int y, int n,vector<vector<bool>>vis,vector<vector<int>>maze){
  return x<n&&y<n&&x>=0&&y>=0&&!vis[x][y]&&maze[x][y];
}

void solve(vector<vector<int>>&maze,vector<vector<bool>>&vis,int n,int x,int y,vector<vector<int>>&ans){
    if(x==n-1&&y==n-1){
      ans.push_back(transform(vis,n));
      return;
    }

  //left
  if(check(x,y-1,n,vis,maze)){
    vis[x][y-1]=true;
    solve(maze,vis,n,x,y-1,ans);
    vis[x][y-1]=false;
  }
  //right
   if(check(x,y+1,n,vis,maze)){
    vis[x][y+1]=true;
    solve(maze,vis,n,x,y+1,ans);
    vis[x][y+1]=false;
  }

  //top
   if(check(x-1,y,n,vis,maze)){
    vis[x-1][y]=true;
    solve(maze,vis,n,x-1,y,ans);
    vis[x-1][y]=false;
  }

  //bottom
   if(check(x+1,y,n,vis,maze)){
    vis[x+1][y]=true;
    solve(maze,vis,n,x+1,y,ans);
    vis[x+1][y]=false;
  }


}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.

  vector<vector<int>>ans;
  vector<vector<bool>>vis(n,vector<bool>(n,false));
  if(maze[0][0])
  vis[0][0]=true;

  solve(maze,vis,n,0,0,ans);

  return ans;

}