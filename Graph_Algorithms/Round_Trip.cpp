// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<int> ans, vis(n, 0);
    ans.reserve(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    function<void(int, int)> dfs = [&](int x, int y){
        vis[x]=1;
        for(auto& u:adj[x]){
            if(u==y)continue;
            if(vis[u]){
                ans={u, x};
                return;
            }
            dfs(u, x);
            if(!ans.empty()){
                if(ans.size()==1 || ans[0]!=ans.back())ans.push_back(x);
                return;
            }
        }
    };

    for(int i=0; i<n && ans.empty(); i++){
        if(!vis[i])dfs(i, i);
    }

    if(ans.empty())cout<<"IMPOSSIBLE";
    else {
        cout<<ans.size()<<'\n';
        for(auto& u:ans)cout<<u+1<<' ';
    }

    return 0;
}