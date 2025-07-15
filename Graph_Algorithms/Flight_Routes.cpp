// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<long long>> ans(n);
    vector<vector<pair<int, long long>>> adj(n);

    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        adj[--x].push_back({--y, w});
    }

    multiset<pair<long long, int>> f;
    f.insert({0, 0});

    while(!f.empty()){
        auto [t, x]=*f.begin();
        f.erase(f.begin());
        
        if(ans[x].size()==k)continue;
        ans[x].push_back(t);

        for(auto& [u, w]:adj[x]){
            if(ans[u].size()==k)continue;
            f.insert({t+w, u});
        }
    }

    for(auto &u:ans[n-1])cout<<u<<' ';
    
    return 0;
}
