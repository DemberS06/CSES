// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;

const long long mod=1e9+7;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    vector<long long> a(n, 0), dp(n, 0);
    vector<vector<int>> adj(n);
    dp[0]=1;
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--y].push_back(--x);
    }

    function<void(int)> dfs = [&](int x){
        a[x]=1;
        for(auto& u:adj[x]){
            if(!a[u])dfs(u);
            dp[x]=(dp[x]+dp[u])%mod;
        }
    };

    dfs(n-1);

    cout<<dp.back();

    return 0;
}