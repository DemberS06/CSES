// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    vector<vector<pair<int, long long>>> adj(n+1);
    vector<long long> ans(n, 0);
    
    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        adj[--x].push_back({--y, w});
    }
 
    set<pair<long long, int>> f, g;
    f.insert({1, 0});
 
    while(!f.empty()){
        auto [t, x]=*f.begin();
        f.erase(f.begin());
        if(ans[x])continue;
        ans[x]=t;
 
        for(auto& [u, w]:adj[x]){
            f.insert({t+w, u});
            g.insert({t+w/2, u});
        }
    }

    while(!g.empty()){
        auto [t, x]=*g.begin();
        g.erase(g.begin());
        if(ans[x]<t)continue;
        ans[x]=t;
 
        for(auto& [u, w]:adj[x]){
            g.insert({t+w, u});
        }
    }
 
    cout<<ans.back()-1;
 
    return 0;
}