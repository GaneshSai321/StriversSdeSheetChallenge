#include <algorithm>




int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low=1,high=1e5;
    int n=matrix.size(),m=matrix[0].size();
    int mid_place=(n*m)/2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        //we need to calculate no els less than equal to mid.
        int cnt=0;
        for(int i=0;i<n;i++){
            int ind=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            cnt+=ind;
        }

        if(cnt>mid_place) high=mid-1;
        else low=mid+1;
    }
    return low;

}