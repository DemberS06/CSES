// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

struct Dinic{
    struct Edge{
        int to, rev, id;
        long long cap;
        Edge(int _to, int _rev, long long _cap, int _id): to(_to), rev(_rev), cap(_cap), id(_id) {}
    };

    int n, s, t, id=0;
    vector<vector<Edge>> adj;
    vector<int> dis, it, vis;

    Dinic(int _n): n(_n), adj(n+1), it(n+1), dis(n+1), vis(n*n, 0) {}

    void add_edge(int u, int v){
        adj[u].push_back(Edge(v, adj[v].size(), 1, ++id));
        adj[v].push_back(Edge(u, adj[u].size()-1, 0, 0));
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

    void resid(int x, vector<int>& path){
        path.push_back(x);
        if(x==t)return;
        for(auto& e:adj[x]){
            if(!e.id || vis[e.id] || e.cap)continue;
            vis[e.id]=1;
            resid(e.to, path);
            return;
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

    int k=G.max_flow(1, n);

    cout<<k<<"\n";
    vector<int> path;

    for(int i=0; i<k; i++){
        G.resid(1, path);
        cout<<path.size()<<"\n";
        for(auto& u:path)cout<<u<<' ';
        cout<<"\n";
        path.clear();
    }

    return m+1;
}