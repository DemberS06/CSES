// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin>>n;

    vector<long long> dp(n+1, 0);
    dp[0]=1;

    for(int i=2; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])*(i-1)%mod;
    }

    cout<<dp.back();

    return 0;
}