// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;

    cin>>n>>m;

    vector<int> a(n), pre(n), cmp(n), v;
    vector<vector<int>> adj(n), jda(n);

    for(auto& u:a)cin>>u;

    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        jda[y].push_back(x);
    }

    int k=0;

    function<void(int, int, vector<int>&, vector<vector<int>>&)> kosaraju = [&](int x, int f, vector<int>& a, vector<vector<int>>& adj){
        k+=f;
        a[x]=k;
        for(auto& u:adj[x]){
            if(a[u])continue;
            kosaraju(u, f, a, adj);
        }
        if(f)v.push_back(x);
    };

    for(int i=0; i<n; i++){
        if(!pre[i])kosaraju(i, 1, pre, adj);
    }

    k=1;

    while(!v.empty()){
        auto x=v.back();
        v.pop_back();
        if(!cmp[x])kosaraju(x, 0, cmp, jda), k++;
    }

    vector<vector<int>> ady(k);
    vector<long long> sum(k, 0), b(k, 0);
    
    for(int i=0; i<n; i++){
        for(auto& u:adj[i])ady[cmp[i]].push_back(cmp[u]);
        b[cmp[i]]+=a[i];
    }

    function<void(int)> dfs = [&](int x){
        sort(ady[x].begin(), ady[x].end());
        int y=0;
        for(auto& u:ady[x]){
            if(y==u || u==x)continue;
            if(!sum[u])dfs(u);
            sum[x]=max(sum[u], sum[x]);
            y=u;
        }
        sum[x]+=b[x];
    };

    long long ans=0;

    for(int i=1; i<k; i++){
        if(!sum[i])dfs(i);
        ans=max(ans, sum[i]);
    }

    cout<<ans;

    return 0;
}