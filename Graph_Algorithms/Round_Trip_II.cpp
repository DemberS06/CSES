// hola soy Dember :D
#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int n, m, k=1;
    cin>>n>>m;
 
    vector<int> a(n, 0), b(n, 0), c(n, 0), v, ans;
    vector<vector<int>> adj(n), jda(n);
    
    for(int i=0, x, y; i<m; i++){
        cin>>x>>y;
        adj[--x].push_back(--y);
        jda[y].push_back(x);
    }
 
    function<void(int, int, vector<int>&, vector<vector<int>>&)> kosaraju = [&](int x, int f, vector<int>& vis, vector<vector<int>>& adj){
        k+=f;
        vis[x]=k;
        for(auto& u:adj[x]){
            if(vis[u])continue;
            kosaraju(u, f, vis, adj);
        }
        if(f)v.push_back(x);
    };
 
    for(int i=0; i<n; i++){
        if(!a[i])kosaraju(i, 1, a, adj);
    }
 
    k=0;
 
    while(!v.empty()){
        auto x=v.back();
        v.pop_back();
        if(!b[x])k++, kosaraju(x, 0, b, jda);
    }

    function<void(int)> dfs = [&](int x){
        c[x]=1;
        for(auto& u:adj[x]){
            if(b[u]!=b[x])continue;
            if(c[u]){
                ans={u, x};
                return;
            }
            dfs(u);
            if(!ans.empty()){
                if(ans.size()==1 || ans[0]!=ans.back())ans.push_back(x);
                return;
            }
        }
    };

 
    for(int i=0; i<n && ans.empty(); i++){
        if(!c[i])dfs(i);
    }
 
    if(ans.empty())cout<<"IMPOSSIBLE";
    else {
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<'\n';
        for(auto& u:ans)cout<<u+1<<' ';
    }
 
    return 0;
}