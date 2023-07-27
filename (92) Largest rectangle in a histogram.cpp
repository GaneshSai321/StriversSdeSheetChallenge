 #include<stack>

 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   stack<int>st;
   int n = heights.size();
   vector<int>lse(n,-1),rse(n,n);
   //calculate left smaller elements
   for(int i =0;i<n;i++){
     while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
     if(!st.empty()) lse[i] = st.top();
     st.push(i);
   }
   //clear the stack
   while(!st.empty()) st.pop();

   //calculate right smaller elements
  for(int i =n-1;i>=0;i--){
    while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
     if(!st.empty()) rse[i] = st.top();
     st.push(i);
  }

//   for(int i =0;i<n;i++) cout<<lse[i]<<" ";
//   cout<<endl;
//   for(int i =0;i<n;i++) cout<<rse[i]<<" ";
// cout<<endl;

  int ans = 0;

  for(int  i =0;i<n;i++){
    ans = max(ans, heights[i]*(rse[i]-lse[i]-1));
  }
  return ans;

 }