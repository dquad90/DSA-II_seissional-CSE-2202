#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}
int main()
{
    int s;
    cin>>s;
    int n;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    //Step 1: Take dp table of size s+1
    int dp[s+1];
    //Step 2a: Initialize all values by Infinity
    for(int i=0; i<=s; i++){
        dp[i] = INT_MAX; 
    }
    //Step 2b: Make first item as 0
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            //Previous values are already stored, so only current values will be 
            //updated. Reduced complexity than previous one.
            if(j>= coins[i-1] && dp[j- coins[i-1]]!= INT_MAX){
                dp[j] = min(dp[j], 1+dp[j- coins[i-1]]);
            }
        }
    }
    if(dp[s]!= INT_MAX){
        cout<<"Min Number of Coins: "<<dp[s];
    }
    else{
        cout<<"Not Possible!";
    }
}
