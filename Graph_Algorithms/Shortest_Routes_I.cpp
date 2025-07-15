// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;

    vector<long long> ans(n, 0);
    vector<vector<pair<int, long long>>> adj(n+1);
    
    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        adj[--x].push_back({--y, w});
        adj[y].push_back({x, w});
    }

    set<pair<long long, int>> f;
    f.insert({1, 0});

    while(!f.empty()){
        auto [t, id]=*f.begin();
        f.erase({t, id});
        if(ans[id])continue;
        ans[id]=t;

        for(auto& [u, w]:adj[id]){
            if(ans[u])continue;
            f.insert({t+w, u});
        }
    }

    for(auto& u:ans)cout<<u-1<<' ';

    return 0;
}