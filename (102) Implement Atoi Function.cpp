#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int ans = 0;
    bool flag = false;
    int n = str.length();
    for(int i = 0;i<n;i++){
        if(str[i]>='0'&&str[i]<='9'){
            ans=ans*10;
            ans += str[i]-'0';
        }
        else if (str[i]=='-') flag =true;
    }
    if(flag) return -ans;
    return ans;
}