// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

const long long mod=1e9+7;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, long long>>> ady(n), yda(n);
    vector<vector<int>> adj(n);
    vector<int> dp(n, 0), vis(n, 0), mn(n, 0), a(n, 0), mx(n, 0); dp[0]=1;
    vector<long long> cost(n, 0);

    for(int i=0, x, y, w; i<m; i++){
        cin>>x>>y>>w;
        ady[--x].push_back({--y, w});
        yda[y].push_back({x, w});
    }

    set<pair<long long, int>> f;
    f.insert({1, 0});

    while(!f.empty()){
        auto [t, id] = *f.begin();
        f.erase(f.begin());
        
        if(cost[id])continue;
        cost[id]=t;
        for(auto &[u, w]:ady[id]){
            if(cost[u])continue;
            f.insert({t+w, u});
        }
    }

    function<void(int)> build = [&](int x){
        vis[x]=1;
        for(auto& [u, w]:yda[x]){
            if(cost[u]==cost[x]-w){
                adj[u].push_back(x);
                if(!vis[u])build(u);
                dp[x]=(dp[x]+dp[u])%mod;
            }
        }
    };

    build(n-1);

    queue<int> q;
    q.push(0);
    mn[0]=1;

    while(!q.empty()){
        auto x=q.front();
        q.pop();

        for(auto& u:adj[x]){
            a[u]++;
            if(mn[u])continue;
            mn[u]=mn[x]+1;
            q.push(u);
        }
    }

    q.push(0);
    mx[0]=1;

    while(!q.empty()){
        auto x=q.front();
        q.pop();

        for(auto& u:adj[x]){
            mx[u]=max(mx[u], mx[x]+1);
            a[u]--;
            if(a[u])continue;
            q.push(u);
        }
    }

    cout<<cost.back()-1<<' ';
    cout<<dp.back()<<' ';
    cout<<mn.back()-1<<' ';
    cout<<mx.back()-1<<' ';

    return 0;
}