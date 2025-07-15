// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<int> vis(n+1, 0);
    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> ans;
    ans.reserve(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(int)> dfs = [&](int x){
        if(vis[x])return;
        vis[x]=1;
        for(auto& u:adj[x])dfs(u);
    };

    dfs(1);

    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        ans.push_back({1, i});
        dfs(i);
    }

    cout<<ans.size()<<'\n';
    for(auto& [x, y]:ans)cout<<x<<' '<<y<<"\n";

    return 0;
}