 #include <bits/stdc++.h> 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here
    vector<int> nse(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        int cur=arr[i];
        while(!st.empty()&&st.top()>=cur) st.pop();
        if(st.empty()) nse[i]=-1;
        else nse[i]=st.top();
        st.push(cur);
    }
    return nse;
}
