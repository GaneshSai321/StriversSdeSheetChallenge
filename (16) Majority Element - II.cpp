#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int cnt1=0,cnt2=0;
    int ele1=-1,ele2=-1;

    int n= arr.size();

    for(int i=0;i<n;i++){
        //current element
        int ele=arr[i];

        if(cnt1==0&&ele!=ele2){
            cnt1=1;
            ele1=ele;
        }
        else if(cnt2==0&&ele!=ele1){
            cnt2=1;
            ele2=ele;
        }
        else if(ele==ele1) cnt1++;
        else if (ele==ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    //Manual check whether they are majority elements;
    cnt1=0;cnt2=0; //reset cnt values

    for(int i=0;i<n;i++){
        int ele=arr[i];
        if(ele==ele1) cnt1++;
        else if (ele==ele2) cnt2++;
    }

    vector<int>ans;
    if(cnt1>n/3) ans.push_back(ele1);
    if(cnt2>n/3) ans.push_back(ele2);

    return ans;

}