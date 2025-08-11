// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

struct HK{
    int n,m;
    vector<vector<int>> adj;
    vector<int> pairU, pairV, dist;

    HK(int _n,int _m): n(_n), m(_m){
        adj.assign(n+1,{});
        pairU.assign(n+1,0);
        pairV.assign(m+1,0);
        dist.assign(n+1,0);
    }

    bool bfs(){
        queue<int> q;
        for(int u=1;u<=n;u++){
            if(pairU[u]==0){
                dist[u]=0;
                q.push(u);
            } else dist[u]=1e9;
        }
        bool found=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:adj[u]){
                int pu=pairV[v];
                if(pu==0) found=1;
                else if(dist[pu]==1e9){
                    dist[pu]=dist[u]+1;
                    q.push(pu);
                }
            }
        }
        return found;
    }

    bool dfs(int u){
        for(auto& v:adj[u]){
            int pu=pairV[v];
            if(pu==0 || (dist[pu]==dist[u]+1 && dfs(pu))){
                pairU[u]=v;
                pairV[v]=u;
                return 1;
            }
        }
        dist[u]=1e9;
        return 0;
    }

    int max_matching(){
        int flow=0;
        while(bfs()){
            for(int u=1; u<=n; u++){
                if(pairU[u]==0 && dfs(u))flow++;
            }
        }
        return flow;
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m, k; 
    cin>>n>>m>>k;
    
    HK G(n,m);

    while(k--){
        int a, b; 
        cin>>a>>b;
        G.adj[a].push_back(b);
    }
    
    for(int i=1; i<=n; i++)sort(G.adj[i].begin(),G.adj[i].end());

    int ans=G.max_matching();
    cout<<ans<<"\n";

    for(int i=1; i<=n; i++){
        if(G.pairU[i])cout<<i<<" "<<G.pairU[i]<<"\n";
    }

    return k+1;
}
