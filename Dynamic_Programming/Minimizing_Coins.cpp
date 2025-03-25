//Hola soy Dember :D

#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int n, x;
    cin>>n>>x;

    vector<int> a(n), dp(x+1, 0);

    for(auto &u:a)cin>>u;
    for(int i=1; i<=x; i++){
        dp[i]=1e6+5;
        for(auto &u:a){
            if(u>i)continue;
            dp[i]=min(dp[i],dp[i-u]+1);
        }
    }

    if(dp[x]>1e6)cout<<-1;
    else cout<<dp[x];

    return 0;
}