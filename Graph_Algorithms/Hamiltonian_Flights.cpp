// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int dp[20][1<<20], vis[20][1<<20];

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin>>n>>m;
    k=1<<n;

    vector<vector<int>> dp(n, vector<int> (k, 0)), vis=dp, adj(n);

    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
    }

    queue<pair<int, int>> q;
    q.push({0, 1});
    vis[0][1]=dp[0][1]=1;

    while(!q.empty()){
        auto [x, id] = q.front();
        q.pop();

        if(x==n-1)continue;

        for(auto& u:adj[x]){
            if((id>>u)&1)continue;
            int nw_id=id+(1<<u);
            dp[u][nw_id]+=dp[x][id];
            if(dp[u][nw_id]>=mod)dp[u][nw_id]-=mod;
            if(!vis[u][nw_id])q.push({u, nw_id}), vis[u][nw_id]=1;
        }
    }

    cout<<dp[n-1][k-1]<<"\n";

    return 0;
}