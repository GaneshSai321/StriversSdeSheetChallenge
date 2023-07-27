#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int cnt=0;
    cnt+=amount/1000;
    amount%=1000;
    cnt+=amount/500;
    amount%=500;
    cnt+=amount/100;
    amount%=100;
    cnt+=amount/50;
    amount%=50;
    cnt+=amount/20;
    amount%=20;
    cnt+=amount/10;
    amount%=10;
    cnt+=amount/5;
    amount%=5;
    cnt+=amount/2;
    amount%=2;
    cnt+=amount;
    return cnt;
}
