
vector<int>format(vector<vector<int>>board,int n){
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    return temp;
}

bool isSafe(int row,int col,vector<vector<int>>board,int n){
    
    for(int j=col-1;j>=0;j--) if(board[row][j]) return false;
    int r=row,c=col;
    while(r>=0&&c>=0){
        if(board[r][c])return false;
        r--;
        c--;
    }
    r=row;c=col;
    while(r<n&&c>=0){
        if(board[r][c]) return false;
        r++;
        c--;
    }
    return true;
}

void solve(int n,vector<vector<int>>&board,int col,vector<vector<int>>&ans){
    if(col==n) {
        ans.push_back(format(board,n));
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]=1;
            solve(n,board,col+1,ans);
            board[row][col]=0;
        }
    }

}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>ans,board(n,vector<int>(n,0));

    solve(n,board,0,ans);

    return ans;
}