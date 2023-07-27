#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>>ans;
    // cout<<n<<endl;
    vector<int>v(2);
    v[0]=intervals[0][0];
    v[1]=intervals[0][1];
    // ans.push_back(v);
    for(int i=1;i<n;i++){
         //cout<<v[0]<<" "<<v[1]<<"... "<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        if(intervals[i][0]<=v[1]){
            v[1]=max(v[1],intervals[i][1]);
            // v[0]=min(v[0],intervals[i][0]);
        }
        else {
            ans.push_back(v);
            v[0]=intervals[i][0];
            v[1]=intervals[i][1];
        }
    }

    int s=ans.size();
    // cout<<v[0]<<" "<<v[1]<<endl;
    if(s>0){
        if(ans[s-1][0]!=v[0]||ans[s-1][1]!=v[1]) ans.push_back(v);
    }
    else ans.push_back(v);


    return ans;
}
