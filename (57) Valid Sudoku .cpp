bool is_valid(int matrix[9][9],int k,int row,int col){
    int boxr=row/3;
    int boxc=col/3;

    int indr=boxr*3;
    int indc=boxc*3;

    for(int i=indr;i<indr+3;i++){
        for(int j=indc;j<indc+3;j++){
            if(matrix[i][j]==k) return false;
        }
    }

    for(int i=0;i<9;i++) if(matrix[i][col]==k) return false; 
    for(int i=0;i<9;i++) if(matrix[row][i]==k) return false;
    
    return true;
}


bool solve(int matrix[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(is_valid(matrix,k,i,j)) {
                        matrix[i][j]=k;
                        if(solve(matrix)) return true;
                        matrix[i][j]=0;
                    }
                   
                }
                return false;
            }
        }
    }

    return true;
}



bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(matrix);
}







