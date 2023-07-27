#include <iostream>
#include <algorithm>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({finish[i],i});
    }

    sort(v.begin(),v.end());

    int endTime=v[0].first;

    int ans=0;
    ans++;

    for(int i=1;i<n;i++){
        int ind=v[i].second;
        if(start[ind]>=endTime){
            ans++;
            endTime=v[i].first;
        }
    }

    return ans;
}

