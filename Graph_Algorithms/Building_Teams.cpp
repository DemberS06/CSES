// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, ok=1;
    cin>>n>>m;

    vector<int> ans(n, 0);
    vector<vector<int>> adj(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    function<void(int)> dfs = [&](int x){
        for(auto& u:adj[x]){
            if(ans[u]==ans[x])ok=0;
            if(ans[u])continue;
            ans[u]=ans[x]^3;
            dfs(u);
        }
    };

    for(int i=0; i<n; i++){
        if(!ans[i])ans[i]=1, dfs(i);
    }

    if(!ok)cout<<"IMPOSSIBLE";
    else for(auto& u:ans)cout<<u<<' ';

    return 0;
}