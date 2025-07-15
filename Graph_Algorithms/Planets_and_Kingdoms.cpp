// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, k=1;
    cin>>n>>m;

    vector<int> a(n, 0), ans(n, 0), v;
    vector<vector<int>> adj(n), jda(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        jda[y].push_back(x);
    }

    function<void(int, int, vector<int>&, vector<vector<int>>&)> dfs = [&](int x, int f, vector<int>& vis, vector<vector<int>>& adj){
        k+=f;
        vis[x]=k;
        for(auto& u:adj[x]){
            if(vis[u])continue;
            dfs(u, f, vis, adj);
        }
        if(f)v.push_back(x);
    };

    for(int i=0; i<n; i++){
        if(!a[i])dfs(i, 1, a, adj);
    }

    k=0;

    while(!v.empty()){
        auto x=v.back();
        v.pop_back();
        if(!ans[x])k++, dfs(x, 0, ans, jda);
    }

    cout<<k<<"\n";
    for(auto& u:ans)cout<<u<<' ';

    return 0;
}