// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> jda(n);
    vector<long long> dis(n, -1e18), a(n); dis[0]=0;

    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        adj[--x].push_back({--y, w});
        jda[y].push_back(x);
    }

    function<void(int x, vector<int>&)> bellman = [&](int x, vector<int>& vis){
        if(vis[x])return;
        vis[x]=1;
        for(auto& [u, w]:adj[x]){
            dis[u]=max(dis[u], dis[x]+w);
            bellman(u, vis);
        }
    };

    for(int i=0; i<n; i++){
        vector<int> vis(n, 0);
        bellman(0, vis);
    }

    function<void(int x)> dfs = [&](int x){
        if(a[x])return;
        a[x]=1;
        for(auto& u:jda[x]){
            dfs(u);
        }
    };

    vector<long long> ans=dis;
    vector<int> vis(n, 0);
    bellman(0, vis);
    dfs(n-1);

    for(int i=0; i<n; i++){
        if(a[i] && ans[i]!=dis[i]){
            cout<<-1;
            return 0;
        }
    }

    cout<<ans.back();

    return 0;
}