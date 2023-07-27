
bool is_possible(vector<vector<int>>mat,vector<int>col,int color,int ind){
    for(int j=0;j<mat.size();j++){
        if(mat[ind][j]==1&&col[j]==color) return false; 
    }
    return true;
}

bool solve(vector<vector<int>>mat,int m ,vector<int>&col,int ind,int n){
    if(ind==n) return true;

    for(int i=1;i<=m;i++){
        if(is_possible(mat, col ,i,ind)) {
            col[ind]=i;
            if(solve(mat,m,col,ind+1,n)) return true;
            col[ind]=0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>col(n,0);
    if(solve(mat,m,col,0,n)) return "YES";
    return "NO";
}