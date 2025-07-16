// hola soy Dember :D
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin>>m>>n;

    vector<int> a(2*n, 0), ans(2*n, 0), v;
    vector<vector<int>> adj(2*n), jda(2*n);

    auto T = [](int x){
        if(x>0)return 2*x-1;
        else return -2*(x+1);
    };

    auto Push = [&](int x, int y){
        adj[T(x)].push_back(T(y));
        jda[T(y)].push_back(T(x));
    };

    while(m--){
        int x, y;
        char c;
        cin>>c>>x;
        if(c=='-')x*=-1;
        cin>>c>>y;
        if(c=='-')y*=-1;
        Push(-x, y);
        Push(-y, x);
    }

    int k=0;

    function<void(int, int, vector<int>&, vector<vector<int>>&)> dfs = [&](int x, int f, vector<int>& vis, vector<vector<int>>& adj){
        k+=f;
        vis[x]=k;
        for(auto& u:adj[x]){
            if(vis[u])continue;
            dfs(u, f, vis, adj);
        }
        if(f)v.push_back(x);
    };
 
    for(int i=0; i<2*n; i++){
        if(!a[i])dfs(i, 1, a, adj);
    }
    
    k=0;
    
    while(!v.empty()){
        auto x=v.back();
        v.pop_back();
        if(!ans[x])k++, dfs(x, 0, ans, jda);
    }
    
    string s(n, '-');
    
    for(int i=0; i<n; i++){
        if(ans[2*i]==ans[2*i+1]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(ans[2*i]<ans[2*i+1])s[i]='+';
    }

    for(auto& u:s)cout<<u<<' ';

    return m+1;
}