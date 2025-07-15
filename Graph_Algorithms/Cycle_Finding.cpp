// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(int i=0; i<m; i++)cin>>edges[i].u>>edges[i].v>>edges[i].w;

    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int cycle_end=-1;

    for(int i=1; i<=n; i++) {
        cycle_end=-1;
        for(auto& e:edges) {
            if(dist[e.u]+e.w<dist[e.v]) {
                dist[e.v]=dist[e.u]+e.w;
                parent[e.v]=e.u;
                cycle_end=e.v;
            }
        }
    }

    if(cycle_end==-1){
        cout<<"NO\n";
        return 0;
    }

    int y=cycle_end;
    for(int i=0; i<n; i++)y=parent[y];

    vector<int> ans;
    for(int x=y;; x=parent[x]) {
        ans.push_back(x);
        if(x==y && ans.size()>1) break;
    }
    reverse(ans.begin(), ans.end());

    cout<<"YES\n";
    for(auto& u: ans)cout<<u<<' ';

    return 0;
}