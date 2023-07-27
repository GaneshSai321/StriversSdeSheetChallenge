#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int low=0,profit=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]-prices[low]>profit){
            profit=prices[i]-prices[low];
        }
        else if(prices[i]-prices[low]<0){
            low=i;
        }
    }
    return profit;
}