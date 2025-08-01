// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;

    vector<bool> dp(n+1, 0);
    vector<int> a(k);

    for(auto &u:a)cin>>u;

    for(int i=1; i<=n; i++){
        for(auto& u:a){
            if(u>i)continue;
            if(!dp[i-u])dp[i]=1;
        }
        if(dp[i])cout<<'W';
        else cout<<'L';
    }

    return 0;
}