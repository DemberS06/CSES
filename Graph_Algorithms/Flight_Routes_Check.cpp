// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<int> a(n, 0), b(n, 0);
    vector<vector<int>> adj(n), jda(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        jda[y].push_back(x);
    }

    function<void(int, vector<int>&, vector<vector<int>>&)> dfs = [&](int x, vector<int>& vis, vector<vector<int>>& adj){
        vis[x]=1;
        for(auto& u:adj[x]){
            if(vis[u])continue;
            dfs(u, vis, adj);
        }
    };

    dfs(0, a, adj);
    dfs(0, b, jda);

    for(int i=0; i<n; i++){
        if(!a[i]){
            cout<<"NO\n";
            cout<<"1 "<<i+1;
            return 0;
        }
        if(!b[i]){
            cout<<"NO\n";
            cout<<i+1<<" 1";
            return 0;
        }
    }

    cout<<"YES";

    return 0;
}