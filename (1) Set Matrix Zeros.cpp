#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	vector<bool>rows(matrix.size(),false),cols(matrix[0].size(),false);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[i].size();j++){
			if(matrix[i][j]==0) {
				rows[i]=true;
				cols[j]=true;
			}
			
		}
	}

	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			if(rows[i]||cols[j]) matrix[i][j]=0;
		}
	}
}