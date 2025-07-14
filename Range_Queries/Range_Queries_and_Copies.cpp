// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
struct Fenwick{
    int n;
    vector<long long> sum;
 
    Fenwick(int _n): n(_n), sum(n+1, 0){}
 
    void update(int i, long long delta){
        for(; i<=n; i+=-i&i)sum[i]+=delta;
    }
 
    long long query(int i){
        long long res=0;
        for(; i>0; i-=-i&i)res+=sum[i];
        return res;
    }
 
    long long query(int l, int r){
        return query(r)-query(l-1);
    }
};
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m;
    cin>>n>>m;
 
    vector<long long> a(n+1);
    Fenwick fwk(n);

    for(int i=1; i<=n; i++){
        cin>>a[i];
        fwk.update(i, a[i]);
    }

    vector<vector<long long>> adj[m+1];
    int x=1, y=0;

    while(m--){
        int t, k, a, b;
        cin>>t>>k;
        if(t==1){
            cin>>a>>b;
            adj[k].push_back({0, a, b});
        }
        if(t==2){
            cin>>a>>b;
            adj[k].push_back({++y, a, b});
        }
        if(t==3)adj[k].push_back({-1, ++x});
    }

    vector<long long> ans(y);

    function<void(int)> dfs = [&](int x){
        for(auto &u:adj[x]){
            if(u[0]==-1)dfs(u[1]);
            else if(u[0])ans[u[0]-1]=fwk.query(u[1], u[2]);
            else fwk.update(u[1], u[2]-a[u[1]]), swap(a[u[1]], u[2]);
        }
        reverse(adj[x].begin(), adj[x].end());
        for(auto &u:adj[x]){
            if(u[0])continue;
            fwk.update(u[1], u[2]-a[u[1]]);
            swap(a[u[1]], u[2]);
        }
    };
    
    dfs(1);

    for(auto& u:ans)cout<<u<<"\n";
    
    return m+1;
}