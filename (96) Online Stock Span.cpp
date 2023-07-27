#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int>ans;
    stack<int>st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && price[i]>=price[st.top()]) st.pop();

        if(!st.empty()) ans.push_back(i-st.top());
        else {
            // cout<<"here "<<i<<endl;
            ans.push_back(i+1); 
        }


        st.push(i);
    }
    return ans;
}