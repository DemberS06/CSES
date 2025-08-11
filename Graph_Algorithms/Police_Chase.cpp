// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

struct Dinic{
    struct Edge{
        int to, rev;
        long long cap;
        Edge(int _to, int _rev, long long _cap): to(_to), rev(_rev), cap(_cap) {}
    };

    int n, s, t;
    vector<vector<Edge>> adj;
    vector<int> dis, it, vis;

    Dinic(int _n): n(_n), adj(n+1), it(n+1), dis(n+1), vis(n+1, 0) {}

    void add_edge(int u, int v){
        adj[u].push_back(Edge(v, adj[v].size(), 1));
        adj[v].push_back(Edge(u, adj[u].size()-1, 1));
    }

    bool bfs(){
        fill(dis.begin(), dis.end(), 0);
        queue<int> q;
        q.push(s);
        dis[s]=1;

        while(!q.empty()){
            auto x=q.front();
            q.pop();

            for(auto& e:adj[x]){
                if(dis[e.to] || !e.cap)continue;
                dis[e.to]=dis[x]+1;
                q.push(e.to);
            }
        }
        return dis[t]>0;
    }

    long long dfs(int x, long long f){
        if(x==t)return f;
        
        for(int &i=it[x]; i<adj[x].size(); i++){
            auto &e=adj[x][i];
            if(dis[x]!=dis[e.to]-1 || !e.cap)continue;
            long long tr=dfs(e.to, min(f, e.cap));
            if(!tr)continue;
            e.cap-=tr;
            adj[e.to][e.rev].cap+=tr;
            return tr;
        }

        return 0;
    }

    long long max_flow(int _s, int _t){
        s=_s, t=_t;
        long long flow=0;

        while(bfs()){
            fill(it.begin(), it.end(), 0);
            while(true){
                long long pushed=dfs(s, 1e18);
                if(!pushed)break;
                flow+=pushed;
            }
        }

        return flow;
    }

    void resid(int x){
        vis[x]=1;
        for(auto& e:adj[x]){
            if(vis[e.to] || !e.cap)continue;
            resid(e.to);
        }
    }
};

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    Dinic G(n);

    while(m--){
        int x, y;
        cin>>x>>y;
        G.add_edge(x, y);
    }

    cout<<G.max_flow(1, n)<<"\n";

    G.resid(1);

    for(int i=1; i<=n; i++){
        if(!G.vis[i])continue;
        for(auto& e:G.adj[i]){
            if(G.vis[e.to])continue;
            cout<<i<<' '<<e.to<<"\n";
        }
    }

    return m+1;
}