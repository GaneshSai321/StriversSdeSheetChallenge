int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0,j=0,ans=0,cnt=0;
    while(cnt<k&&j<n){
        if(arr[j]==0) cnt++;
        j++;
    }
    if(j==n) return n;
    j--;

    while(i<n&&j<n){
      // cout<<i<<" "<<j<<endl;
      ans=max(ans,j-i+1);
      j++;
      if (arr[j] != 1)  {
        while (arr[i] != 0) i++;
        i++;
      }
    }

    ans=max(ans,j-i);
    return ans;
}
