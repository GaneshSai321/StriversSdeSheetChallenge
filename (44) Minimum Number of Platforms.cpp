int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int cnt=1,maxCnt=1;
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1,j=0;

    while(i<n&&j<n){
        if(at[i]<=dt[j]){
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        maxCnt=max(maxCnt,cnt);
    }
    return maxCnt;
}