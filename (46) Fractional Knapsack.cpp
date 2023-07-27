#include <bits/stdc++.h> 

bool compare(pair<int,int>a,pair<int,int>b){
    return (double)a.second/a.first > (double) b.second/b.first;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    
    sort(items.begin(),items.end(),compare);

   
    double profit=0;
    int i=0;
    while(w&&i<n){
        int pick=min(w,items[i].first);
        profit+= pick * (double) items[i].second/items[i].first;
        w-=pick;
        i++;
        
    }

    return profit;

}