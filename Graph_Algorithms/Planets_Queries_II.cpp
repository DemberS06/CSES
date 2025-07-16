// hola soy Dember :D
#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>n>>m;

    vector<int> a(n), pre(n), pos(n), b(n, 0), c(n, 1), d(n, 0), root(n), id(n, 0), p(n), tm(n+1, 0);
    vector<vector<int>> adj(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        adj[--a[i]].push_back(i);
        b[a[i]]++;
    }

    queue<int> q;

    for(int i=0; i<n; i++){
        if(b[i]==0)q.push(i);
    }

    while(!q.empty()){
        auto i=q.front();
        q.pop();
        c[i]=0;
        b[a[i]]--;
        if(!b[a[i]])q.push(a[i]);
    }

    function<void(int, int&)> dfs = [&](int x, int& y){
        pre[x]=++y;
        
        for(auto& u:adj[x]){
            if(c[u])continue;
            root[u]=root[x];
            d[u]=d[x]+1;
            dfs(u, y);
        }
        
        pos[x]=++y;
    };

    for(int i=0, cnt=1; i<n; i++){
        if(!c[i] || id[i])continue;
        for(int x=i; x!=i || !id[x]; x=a[x]){
            root[x]=x;
            id[x]=cnt;
            tm[id[x]]++;
            p[x]=tm[id[x]];
            int y=0;
            dfs(x, y);
        }
        cnt++;
    }

    while(m--){
        int x, y;
        cin>>x>>y; x--;y--;

        if(c[x] && !c[y]){
            cout<<"-1\n";
            continue;
        }

        if(!c[x] && !c[y]){
            if(root[x]!=root[y] || pre[y]>pre[x] || pos[x]>pos[y])cout<<"-1\n";
            else cout<<d[x]-d[y]<<"\n";
            continue;
        }

        int ans=d[x];
        x=root[x];

        if(id[x]!=id[y]){
            cout<<"-1\n";
            continue;
        }

        ans+=(p[y]-p[x]+tm[id[x]])%tm[id[x]];
        cout<<ans<<"\n";
    }

    return m+1;
}