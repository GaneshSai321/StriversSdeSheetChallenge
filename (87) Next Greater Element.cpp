#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int>nge(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int cur=arr[i];
        while(!st.empty()&&st.top()<=cur) st.pop();
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        st.push(cur);
    }
    return nge;
}