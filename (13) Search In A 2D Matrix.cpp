bool searchMatrix(vector<vector<int>>& mat, int target) {
   int row=0;
   bool ans=false;
   for(int i=0;i<mat.size();i++){
       row=i;
       if(mat[i][0]>target) {
           row=i-1;
           break;
       }
   }
   for(int j=0;j<mat[0].size();j++){
       if(mat[row][j]==target){
           ans=true;
           break;
       }
   }  
   return ans;     
}