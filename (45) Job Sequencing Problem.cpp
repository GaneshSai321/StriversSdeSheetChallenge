#include <bits/stdc++.h> 

bool compare(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n=jobs.size();
    sort(jobs.begin(),jobs.end(),compare);
    vector<bool>filled;
    int profit=0;
    for(int i=0;i<n;i++){
        int cur_size=filled.size();
        if(jobs[i][0]>cur_size){
            vector<bool>extra(jobs[i][0]-cur_size,false);
            filled.insert(filled.end(),extra.begin(),extra.end());
            cur_size=jobs[i][0];
            filled[cur_size-1]=true;
            profit+=jobs[i][1];
        }
        else{
            int target_ind=jobs[i][0]-1;
            while(target_ind>=0&&filled[target_ind]) target_ind--;
            if(target_ind>=0) {
                filled[target_ind]=true;
                profit+=jobs[i][1];
            }
        }
    }




    return profit;
}
