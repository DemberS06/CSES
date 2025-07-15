// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    long long ans=0;
    set<vector<int>> f;
    vector<int> root(n);
    vector<vector<int>> component(n);

    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        f.insert({w, --x, --y});
    }

    for(int i=0; i<n; i++)root[i]=i, component[i]={i};

    auto dsu = [&](int x, int y){
        if(component[x].size()<component[y].size())swap(x, y);
        for(auto& u:component[y]){
            root[u]=x;
            component[x].push_back(u);
        }
        component[y].clear();
    };

    while(!f.empty()){
        auto u=*f.begin();
        f.erase(f.begin());

        if(root[u[1]]==root[u[2]])continue;
        dsu(root[u[1]], root[u[2]]);
        ans+=u[0];
    }

    for(auto& u:root){
        if(u!=root[0]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }

    cout<<ans;

    return 0;
}