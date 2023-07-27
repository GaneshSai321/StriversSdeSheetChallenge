#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({end[i],i});
    }

    sort(v.begin(),v.end());

    int endTime=v[0].first;

    vector<int>ans;
    ans.push_back(v[0].second+1);

    for(int i=1;i<n;i++){
        int ind=v[i].second;
        if(start[ind]>endTime){
            ans.push_back(ind+1);
            endTime=v[i].first;
        }
    }

    return ans;
    
}